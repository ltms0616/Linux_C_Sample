#include "stdio.h"

#define likely(x) __builtin_expect(!!(x), 1)

int main(int argc, char** argv)
{
    unsigned int word="a";
    unsigned char bits=8;
    unsigned int input="a";
    int i;
    for( word <<= (32-bits) ; likely(bits); bits--)
    {
        printf("spi MOSI output:\n");
        for(i=0 ; i<32; i++)
        {
            printf("%s",(word & (1<<(31-i)))?"1":"0");
            if(!((i+1)%8) && (i>0))
                printf(":");
        }
        printf("\n");
        printf("spi MISO input:\n");
        word |= input<<(24-bits);
        word <<=1;
        for(i=0 ; i<32; i++)
        {
            printf("%s", (word & (1<<(31-i)))?"1":"0");
            if((!((i+1)%8)) && (i>0))
                printf(":");
        }
        printf("\n\n");
    }
}

