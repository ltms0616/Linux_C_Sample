#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 20
#define LENTH 512

int main(int argc, char **argv)
{
     char *output=NULL;
     int outCount=0;
     char output_tmp[COUNT][LENTH];
     char tmp[LENTH]={0}; 
     int i;
     output = output_tmp[outCount];
     for(i=0; i<6; i++){
         sprintf(tmp, "\r\ntest%d     :test%d", i, i);
         if(i==2){
             outCount++;
             output=output_tmp[outCount];
         }
         strcat(output, tmp);
         memset(tmp, 0, LENTH);
          
         if(i==5){
             strcpy(tmp, "\r\n");
             strcat(output, tmp);
         }
     }

     printf("%s", output);
#if 0  
     for(i=0; i<outCount+1; i++){
         printf("%s",output_tmp[i]);

     }
#endif
     
     return;


}
