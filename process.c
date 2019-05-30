#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int pcount=0, ccount=0;
    int rc;   
    pid_t child_pid;
    
    child_pid = fork();

    while((pcount<8)&&(ccount<11)){ 
        if(child_pid > 0){   
            printf("the child_pid is %d\n", child_pid);
            printf("Current process is parent, the id is %d\n", getpid());
            /*pcount++;
            printf("pcount = %d\n", pcount);*/
            sleep(2);
        }else if(child_pid == 0){
            printf("the child_pid is %d\n", child_pid);
            printf("Current process is child, the id is %d\n", getpid());
            /*ccount++;
            printf("ccount = %d\n", ccount);*/
            sleep(2);
        }else{
            printf("failed!\n");
        }
        pcount++;
    }
    printf("exit while\n");
    rc = wait(NULL);

    return 0;

}
