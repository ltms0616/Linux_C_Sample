#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    int res=0;
    char *buf;

    buf=malloc(sizeof(char)*1024);
    memset(buf, 0, sizeof(char)*1024);
   
    res=system("dd if=/dev/zero of=/home/moorelin/Usb/test_file bs=1M count=100 >>log");  
    if(res){printf("error\n");}
    exit;
}
