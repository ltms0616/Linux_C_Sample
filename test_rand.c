#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
   unsigned int i,j;
   unsigned char rdata;
   struct timeval tv;

   for(j=0; j<21; j++){
       gettimeofday(&tv, NULL);
       printf("usec = %lu   ", tv.tv_usec);
       srand((unsigned)tv.tv_usec+j);
       /*printf("Ten random numbers from 0 to 255\n\n");*/
       for(i=0; i<10; i++){
           rdata = rand()%256;
           printf("0x%x ", rdata);
       }
       printf("\n");
   }
   return 0;
}

