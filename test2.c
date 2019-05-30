#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define BUTTON_1  0x27580001
#define POWER_KEY BUTTON_1


int function1(void)
{
    int res=0;

    res=0;

    return res;

}


int main(int argc, char** argv)
{
    int i=0;
    int res=0;
    for(i=0;i<10;i+=2){
        printf("%d ", i);
    }
    res=function1();
    if(res){
        printf("function fail\n");
        return res;
    }
    printf("function success\n");
    printf("power key = %x\n", POWER_KEY);
    printf("\n");
}
