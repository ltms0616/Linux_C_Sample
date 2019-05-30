#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *bt="hci3";
    int id;
    if(!bt){
        printf("id = 0");
    }else{
        id = atoi(bt+3);
        printf("bluetooth interface: %s, id=%d\n", bt, id);
    }

}
