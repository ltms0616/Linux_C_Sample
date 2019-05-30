#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    unsigned int idx;
    unsigned int mode;
}gpioTable;

gpioTable pioTable[6]={ {6, 0},
                               {7, 1},
                               {8, 0},
                               {9, 2},
                               {10, 1},
                               {11, 0} 
                             };


int main(int argc, char **argv)
{
    unsigned int i=0;
    unsigned int counts=6;

    counts = sizeof(pioTable)/sizeof(gpioTable);

    for(i=0; i<counts; i++)
        printf("gpio idx:%d, direction:%d\n", pioTable[i].idx, pioTable[i].mode);

    return 0;
}
