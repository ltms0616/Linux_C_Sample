#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t child_pid,pr;

    child_pid = fork();
    if(child_pid != 0){
        printf("the child process is %d\n", child_pid);
    }else{
        printf("the parent process is %d\n", child_pid);
    }
    pr=wait(NULL);
    printf("the returned child process: %d\n", pr);
    return 0;
}
