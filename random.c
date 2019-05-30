#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

pthread_t thread_1;
FILE* data_file;


void test_rand()
{
     int i;
     
 
     for(i=0; i< 16; i++){
         fprintf(data_file, "%x", rand()%256);    
     }
     printf("\n");
}

void create_src_data()
{
    int i;

    for(i=0; i<1024; i++){
        test_rand();
    }
}

void* thread_random(void* arg)
{
    int i=0;
    while(i<5){
     create_src_data();
     i++;
    }
    return NULL;
}

int main(int argc, char **argv)
{
     struct timeval tv;
     
     gettimeofday(&tv, NULL);
     srand((unsigned)tv.tv_usec);
    
     data_file = fopen("randam_data","a+");

     pthread_create(&thread_1, NULL, &thread_random, NULL);
     
     pthread_join(thread_1, NULL);

     fclose(data_file);
     return 0;
}
