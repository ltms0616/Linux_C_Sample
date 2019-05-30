#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char** argv)
{
    int fd;

    fd = open("inputfile.txt", O_RDONLY);
    if(fd == -1){
        //fprintf(stderr, "strerror: error opening file: %s\n", strerror(errno));
        perror("perror: error opening file");
        exit(1);
    }


}
