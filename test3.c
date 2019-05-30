#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned int idx=1;
    
    idx >>= 2 ;

    printf("the idx = %u\n", idx);

    return;
}
