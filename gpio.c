#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
    int opt=0;
    char opts[16];
    int q = 1;
    int idx=0;
    int rc=0;
    do{

        printf("Aveiro GPIO test\n"
               "1. GPIO5_3(GE_WAKE_HOST0)\n"
               "2. GPIO5_1(GE_WAKE_HOST1)\n"
               "3. GPIO5_2(PUSH_B)\n"
               "4. GPIO5_6(LED_MB2_R_N)\n"
               "5. GPIO5_4(LED_MB2_G_N)\n"
               "6. GPIO5_5(LED_MB1_R)\n"
               "7. GPIO5_7(LED_MB1_G)\n"
               "8. Quit\n"
               );
        printf("Input:");   
        fgets(opts, 16, stdin);
        /*&idx = fgetc(stdin);*/
        printf("\nInput option is : %s\n", opts);
        idx = atoi(opts);
        switch(idx){
            case 1:
                printf("GPIO5_3 open\n");
                break;
            case 2:
                printf("GPIO5_1 open\n");
                printf("Enter y to set voltage high or others to low\n");
                fgets(opts, 16, stdin);
                if (opts[0] == 'y' || opts[0] == 'Y'){
                    printf("the voltage is high\n");
                }else if(opts[0] != '\n'){
                    printf("the voltage is low\n");
                }else{
                    printf("keep voltage the same\n");
                }
                break;
            case 3:
                printf("GPIO5_2 open\n");
                break;
            case 4:
                printf("GPIO5_6 open\n");
                break;
            case 5:
                printf("GPIO5_4 open\n");
                break;
            case 6:
                printf("GPIO5_5 open\n");
                break;
            case 7:
                printf("GPIO5_7 open\n");
                break;
            case 8:
                printf("Quit test!!!\n");
                q=0;
                break;

            default:
                printf("wrong input, try again\n");
                break;
        }
    }while(q);
}
