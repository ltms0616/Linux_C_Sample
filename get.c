#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* char fgets(char *s, int size, FILE *stream) 
   int fseek(FILE *stream, long offset, int whence)   whence= SEEK_SET ==> offset is related to start of file
								  SEEK_CUR ==> offset is related to current position
                                                          SEEK_END ==> offset is related to end of file
   long ftell(FILE *stream)  currnet position
   void rewind(FILE *stream) set position indicator to the begin of the file
   int fgetc(FILE *stream) read next character from stream, until EOF, return as unsigned char cast to int

   getchar
   getc
   gets
*/

void main(int argc, char** argv)
{
    FILE *pfile;
    char string[100];
    int rc=0;
#if 0   
    pfile = fopen("poem.txt", "r");

    if(pfile == NULL){
        printf("open file fail!");
    }

    printf("fgets example\n");
    if(fgets(string, 200, pfile)){
	puts(string);
    }else{
	printf("fgets fail!\n");
    }
    
    printf("fgets from stdin\n");
    fgets(string, 5, stdin);
    printf("the input is %s\n", string);

    /*rc = fseek(pfile, 0, SEEK_SET);*/
    rewind(pfile);
    printf("current file pointer position = %ld\n", ftell(pfile));  
    printf("fgetc example\n");
    
    rc = fseek(pfile, 15, SEEK_SET);
    rc = fgetc(pfile);
    printf("%d, %c\n", rc, rc);
#endif

    
    return;
}
