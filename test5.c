#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    unsigned long long error_count=0;
    unsigned long long total_count=0;
    double result;
    unsigned long long t=0;

    error_count = 0;
    total_count = 212246519000;

    t = 25*1e11;   
    result =(double)(error_count*10E11/total_count);
    printf("The result is '%e'\n", result);
    printf("the t is '%llu'\n", t);
    return 0;
}
