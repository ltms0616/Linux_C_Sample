#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
void main(int argc, char** argv)
{

    struct stat st;
    int size;
    stat("poem.txt", &st);
    //size=st.st_size;
    printf("The poem.txt size %d byte\n",(int)st.st_size);

    return;
}
