#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define ADV_CMD "abbbbf"
#define TEST_DATA "01234567"
#define TEST_DATA1 "kkkkdd"

int function1(unsigned long word, int idx)
{
    int i=0, len;
    char *buf;

    buf=malloc(sizeof(char)*255);
    memset(buf, 0, sizeof(char)*255);

    strcpy(buf, TEST_DATA1);
    len=strlen(buf);

    return *(buf+idx);
     

}

int main(int argc, char** argv)
{
     unsigned char *buf=NULL;
     unsigned char buf1[255];
     char *cmd=ADV_CMD;
     char *data=TEST_DATA;
     int i=0,size=0, len=0;
     int j=0;
     char out;
     unsigned long outul;
     long outl;
     int bits=0; 

     buf=malloc(sizeof(char)*255);
     memset(buf, 0, sizeof(char)*255);
     strcpy(buf,cmd);

     size = sizeof(buf);
     len = strlen(buf);
     printf("the buf is ");
     for(i=0;i<len;i++){
         printf("%c", *(buf+i));
     }
     printf("\n");
     printf("the size of buf is %d\n", size);
     printf("the length of buf is %d\n", len);
     /*strcat(buf,data);
     printf("the buf is %s\n", buf);
     len = strlen(buf);
     printf("the length of buf is %d\n", len);
     
     strcpy(buf1, buf);
     len=strlen(buf1);
     printf("The buf1 len is %d\n", len);
     */
     printf("Replace the buf to ");
     for(i=0 ;i<len ;i++)
     {
         unsigned long k;
         k = *(buf+i);        
         /*outul = strtoul(&out, NULL, 0);
         outl = strtol(&out, NULL, 36);
         printf("the out is %d, the ul is %lu, the l is %ld\n", out, outul, outl);
         bits = 8;*/
         printf("%c=", *(buf+i));
         printf("%lu =>", k);
         *(buf+i)=function1(k,i);
       
         printf("%c=", *(buf+i));
         k=*(buf+i);
         printf("%lu\n", k);
     }
     printf("\n");
     return 0; 

}
