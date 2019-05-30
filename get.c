#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
/* char fgets(char *s, int size, FILE *stream)  #read in at the most line less than size. Reading stop after EOF or newline.
   int fseek(FILE *stream, long offset, int whence)   #whence= SEEK_SET ==> offset is related to start of file
								  SEEK_CUR ==> offset is related to current position
                                                          SEEK_END ==> offset is related to end of file
   long ftell(FILE *stream)  #currnet position
   void rewind(FILE *stream) #set position indicator to the begin of the file
   int fgetc(FILE *stream) read next character from stream, until EOF, return as unsigned char cast to int

   int getchar(void)   # get one character from stdin , equivalent to getc(stdin); 
   int getc(FILE *stream) # equivalent to fgetc() except that it may be implemented as a macro which evaluate stream more than once   
   char *gets(char *s)   #read a line from stdin into the buffer pointed by s until newline or EOF. NEVER USE THIS FUNTION!!! 
   
*/

int main(int argc, char** argv)
{
    FILE *pfile;
    char string[200];
    char *str;
    int rc=0;
    int c=0;
    int shift=0;
    int len=0;
    int sz;
    struct stat st;    

    pfile = fopen("poem.txt", "r");
    if(pfile == NULL){
        printf("open file fail!");
        return -1;
    }

#if 1
    fseek(pfile, 0L, SEEK_END);
    sz=ftell(pfile);
    rewind(pfile); 
#else   
    stat("poem.txt", &st);
    sz = (int)st.st_size;
#endif

#if 0 
    /* fget example, read from file and stdin(with space is acceptable)*/
    printf("fgets example\n");

    if(fgets(string, 200, pfile)){
	puts(string);
    }else{
	printf("fgets fail!\n");
    }
#else
    printf("fgets from stdin\n");
    fgets(string, 60, stdin);
    if(string[0]=='\n'){
        printf("you press enter\n");
    }else{
        printf("you input %s\n", string);
    }
#endif 

#if 0
    /* rewind the file position and then try fgetc example from file and stdin */
    /*rc = fseek(pfile, 0, SEEK_SET);*/
    rewind(pfile);
    printf("current file pointer position = %ld\n", ftell(pfile));  
    printf("fgetc example\n");
    
    rc = fseek(pfile, 15, SEEK_SET);
    rc = fgetc(pfile);
    printf("%d, %c\n", rc, rc);

    printf("Enter Character:\n");
    rc = getchar();
    printf("Character entered:");
    putchar(rc);
    printf("\n");

    printf("Enter Charcter:\n");
    rc = getc(stdin);
    printf("Character entered:");
    putchar(rc);
    printf("\n");
#endif

#if 0
    /* store whole file into string by fgets */
    str = malloc(700*sizeof(char));
    //memset(str, '0', 700*sizeof(char));  
    printf("Read from Poem.txt\n");  
    while(!feof(pfile)){
          fgets(str+strlen(str), 100, pfile);
          
    }
    printf("%s", str);

#endif
#if 0
    /* store the whole file into string by fgetc */
    memset(str, 0, 700*sizeof(char));
    while((rc = fgetc(pfile))!= EOF){
        c=sprintf(str, "%c", rc);
        str+=c;
        shift+=c;
    } 
    //printf("string len %d\n", shift);
    printf("%s", str-strlen(str));    
#endif
#if 0
    /* put whole file to stdout */
    while(!feof(pfile)){
        rc=getc(pfile);
        putchar(rc);
    }
#endif
#if 0
    /* check the file size*/
    fseek(pfile, 0, SEEK_END);    
    rc=ftell(pfile);
    printf("the poem.txt size %d byte", rc);
    rewind(pfile);
#endif
    fclose(pfile);
    return;
}
