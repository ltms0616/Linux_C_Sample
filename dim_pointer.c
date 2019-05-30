#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void main(int argc, char** argv)
{

    char **param=(char**)malloc(sizeof(char*)*7);
    int i=0;

#if 1 /*array with random memory area*/
    for(i=0; i<7; i++){
        param[i]=(char*)malloc(sizeof(char)*5);
        memset(param[i], '\1', sizeof(char)*5);
    }
    sprintf(param[0], "%s", "DVBS1234567890ABCDEF");
    sprintf(param[1], "%s", "DVBC");
    sprintf(param[6], "%s", "DVBT");

    for(i=0; i<7; i++){
        printf("param %d: %s\n", i, param[i]);
    }
  
    for(i=0; i<7; i++){
        free(param[i]);
    }
   
    free(param);
#endif
#if 0 /* array with continous memeory area*/
    char *trunk=(char*)malloc(sizeof(char)*7*5);

    for(i=0; i<7; i++){
        memset(trunk, '\0', sizeof(char)*5);
        param[i]=trunk;
        trunk+=5;
    }


    sprintf(param[0], "%s", "DVBS1234567890ABCDEF");
    sprintf(param[1], "%s", "DVBC");
    sprintf(param[6], "%s", "DVBT");

    for(i=0; i<7; i++){
        printf("param %d: %s\n", i, param[i]);
    }
  
    free(param);
#endif
}
