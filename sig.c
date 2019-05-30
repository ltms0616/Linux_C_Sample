#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

sig_atomic_t sigusr1_count = 0;

void handler(int signal_number)
{
    ++sigusr1_count;
}


int main(int argc, char** argv)
{
    struct sigaction sa;
    int i=0, count=100;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &handler;
    sigaction(SIGUSR1, &sa, NULL);

    if(argc > 1)
      count=atoi(argv[1]);
    assert(count);
   
    printf("the count is %d\n", count);

    while(i < count){
        i++;
    }
    
    printf("SIGUSR1 was raised %d times\n", sigusr1_count);

    return 0;

}
