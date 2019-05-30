
#include <stdio.h>
#include <stdlib.h>


extern char** environ;

int main(int argc, char** argv)
{

    char** var;
    char* desktop_name = getenv("DESKTOP_NAME");
    char* company_name = getenv("COMPANY");


    if(desktop_name == NULL)
        desktop_name = "moorelin_DT";

    if(company_name == NULL)
        setenv("COMPANY", "SmarDTV", 0);


    printf("the desktop name is %s\n", desktop_name);


    for(var = environ; *var != NULL; ++var){
        printf("%s\n", *var);
    }
    return 0;
}
