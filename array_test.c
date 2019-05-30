#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv)
{
    int pos=0;
    int array1[10]={0,1,2,3,4,5,6,7,8,9};
    int i=0;
    int temp;

    for(i=0; i < 5; i++){
        printf("current pos is %d\n", pos);
        temp = array1[pos++];
        printf("current pos: %d, temp: %d\n", pos, temp);
    } 
}

