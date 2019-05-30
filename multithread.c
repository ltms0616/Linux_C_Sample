#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

pthread_mutex_t mflag;
sem_t scount;
unsigned int num=0;

struct thread_param{
    unsigned char loop;
    unsigned char result1;
    unsigned char result2;
};

void *thread_1(void *argv)
{
     struct thread_param *param = (struct thread_param *)argv;
     int val=0;
     pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
     pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
     int i=0;

     while(param->loop){
         pthread_testcancel();
         usleep(10000);
         num=rand()%256;
         printf("thread 1: 0x%02x\n", num);
         sem_post(&scount);
         sem_getvalue(&scount, &val);
         printf("thread 1 sem count %d\n", val);
         i+=1;
         param->result1 = i;
         pthread_testcancel();
         sleep(2);
     }
     return NULL;
}

void *thread_2(void *argv)
{
    struct thread_param *param = (struct thread_param *)argv;
    unsigned int i=0;
    unsigned int buf=0;
    int val=0;
     
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);    

    sleep(1);
    while(i < 200){
        pthread_testcancel();
        usleep(10000);
        if(sem_trywait(&scount) != EAGAIN){
            buf=num;
            printf("thread 2: 0x%02x\n", buf);
        }else{  
            printf("thread 2: 0x%02x\n", buf);
        }
        sem_getvalue(&scount, &val);
        printf("thread 2 sem count %d\n", val);
        i+=1;
        param->result2 = i;
        sleep(1); 
        pthread_testcancel();
        usleep(10000);
    }
    param->loop=0;
    return NULL;     
}

int main(int argc, char **argv)
{
    pthread_t thread1, thread2;
    struct thread_param param;

    pthread_mutex_init(&mflag, NULL);
    sem_init(&scount, 0, 0);
    memset(&param, 0, sizeof(struct thread_param));

    param.loop = 1;
    param.result1 = 0;
    param.result2 = 0;
    
    pthread_create(&thread1, NULL, thread_1, (void*)&param);
    pthread_create(&thread2, NULL, thread_2, (void*)&param);
    
    getchar();
    pthread_cancel(thread1);
    pthread_cancel(thread2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("result1: %d, result2: %d\n", param.result1, param.result2);

    return 0;

}

