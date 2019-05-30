#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


void print_usage(FILE* stream, int status)
{
    fprintf(stream,"\r\nUsage:\n"
            "    -h, --help    : print the usage\n"
            "    -c, --count   : add count\n"
            "    -n, --name    : name of input\n"
            "    -v, --verbose : print the verbose\n");
    exit(status);
}


void main(int argc, char **argv)
{
    const char const *shortOpts = "hc:n:v";
    const struct option longOpts[] = {
        {"help",    0, NULL, 'h'},
        {"count",   1, NULL, 'c'},
        {"name",    1, NULL, 'n'},
        {"verbose", 0, NULL, 'v'},
        {NULL,      0, NULL,  0 }
    };
    int nextOpt;
    int count=0;
    int verbose=0;
    char *name;

    do{
        nextOpt = getopt_long(argc, argv, shortOpts, longOpts, NULL);
        printf("option: %d, optind: %d, argv: %s\n", nextOpt, optind, argv[optind]);

        switch(nextOpt){
            case 'h':
                print_usage(stdout, EXIT_SUCCESS); 
                break;
            case 'c':
                count = atoi(optarg);
                printf("The count you input is %d\r\n", count);
                break;
            case 'n':
                name = optarg;
                printf("the name you input is %s\r\n", name);
                break;
            case 'v':
                verbose=1;
                break;
            case '?':
                print_usage(stderr, EXIT_FAILURE);
                break;
            case -1:
                break;
            default:
                abort();
        }
    }while(nextOpt != -1); 


    if(verbose){
        int i;
        for(i=0;i<argc;i++){
            printf("the optind %d : %s\r\n", optind, argv[i]); 
        }
    }
    
    exit(0);
}

