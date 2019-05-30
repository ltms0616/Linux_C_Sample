#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(int argc, char** argv)
{
/*
    int scanf(const char *format, ...)  ==> read input from stdin according to format conversion
    int sscanf(const char *str, const char* format, ...)  ==> read input from char string pointed by str
    int fscanf(FILE *stream, const char* format, ...)  ==> read input from the point stream
*/

    int rc=0,i=0;
    char *p;
    char *p1;    
    int len=200;
    FILE *pfile;
    char text[20];    

    p = malloc(len*sizeof(char));
    p1 = malloc(len*sizeof(char));
    pfile = fopen("poem.txt", "r");
#if 0
    printf("*****scanf input*****\n");
    printf("scan wihtout space\n");    
    rc = scanf("%s", p);
    printf("the input is %s\n", p);
    memset(p, 0, len*sizeof(char));
    printf("scan two string with space\n");
    rc = scanf("%s %s", p, p1);
    printf("the input is %s %s\n", p, p1);

    /* Note scanf and fscanf is the same when input is stdin, fscan can also input from other stream*/
    printf("*****fscanf input*****\n");
    memset(p, 0, len*sizeof(char));
    rc = fscanf(stdin, "%s", p);
    printf("the input is %s\n", p);

#endif    
    fscanf(pfile, "%s", p);
    printf("functions read from poem.txt as below\n");
    printf("\nfscanf:\n");
    printf("%s", p);
   
    fgets(p , 200, pfile);
    printf("\nfgets:\n");
    printf("%s", p);
    rc = sscanf(p, "%s", p1);
    printf("\nsscanf:\n");
    printf("%s\n", p1);    

          
    free(p1);
    free(p);


}


