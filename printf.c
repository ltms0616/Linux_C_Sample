/*
    examples of printf, fprintf, sprintf, snprintf, vprintf, vfprintf, vsprintf, vsnprintf
    
    #include <stdio.h>
    int printf(const char *format, ...)
    int fprintf(FILE *stream, const char *format, ...);
    int sprintf(char *str, const char *format, ...);
    int snprintf(char *str, size_t size, const char *format, ...);
    
    #include <stdarg.h>
    int vprintf(const char *format, va_list ap);
    int vfprintf(FILE *stream, const char *format, va_list ap);
    int vsprintf(char *str, const char *format, va_list ap);
    int vsnprintf(char *str, size_t size, const char *format, va_list ap);

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char **argv)
{
    FILE *out, *pfile;
    char *str;
    int len=20;
    int rc;
    int shift=0;
    char *name;
    int age=0;
 
    out = fopen("fprintf.out", "a+");
    pfile = fopen("poem.txt", "r");
#if 0   /* fgets input from stdin , then append to file via fprintf */
    str = malloc(len*sizeof(char));
    if(pfile == NULL){
        fprintf(stderr,"open fprint.out fail\n");
        return; 
    } 
    printf("Enter the charcters to file:\n");
    fgets(str, len, stdin);
    fprintf(pfile, "%s", str);
#endif
#if 0
    str = malloc(200*sizeof(char));
    name = malloc(20*sizeof(char));
    printf("Enter the name:");
    scanf("%s", name);
    printf("Enter the age:");
    scanf("%d", &age);
    sprintf(str, "Name: %s\nAge: %d\n", name, age);
    printf("%s", str);
#endif
    str =(char*)malloc(sizeof(char)*200);
    name = (char*)malloc(sizeof(char)*10);
    fgets(str, 
  
    return;

}
