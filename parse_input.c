#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main(int argc, char **argv)
{

    char **param=(char**)malloc(sizeof(char*)*8);
    //char *trunk=(char*)malloc(sizeof(char)*8*25);
    int i=0, idx=0, next_idx=0;
    char *cmds=(char*)malloc(sizeof(char)*200);
    char *cmd=(char*)malloc(sizeof(char)*25);
    int param_idx=0;
    char *tmp=(char*)malloc(sizeof(char)*25);
    unsigned int freq=0, symrate=0, tuner_idx=0;    
    unsigned char mod=0;

    for (i=0; i<8; i++){
        //memset((char*)trunk, '\0', sizeof(char)*25);
        //param[i]=trunk;
        //trunk+=25;
        param[i]=(char*)malloc(sizeof(char)*25);
        memset((char*)param[i], '\0', sizeof(param[i]));
    }
    
    printf("please input your cmds\n");
    fgets(cmds, 200, stdin);
    i=0;
    while(cmds[i] != ';'){
        if(cmds[i] == ' '){
            //i+=1;   
            printf("param %d, i=%d, idx=%d,\n", param_idx, i, idx);
            snprintf(param[param_idx], i-idx+1, "%s", cmds+idx);
            printf("%s\n", param[param_idx]);  
            //memset(tmp, '\0', sizeof(char)*25);
            idx=i+1;
            param_idx+=1;
        }/*else{
            i+=1;
        }*/ 
        i+=1;
    }
  
    printf("%s\n", param[0]);
 
    if(!strcmp(param[0], "FE_SAT_TUNE")){
        printf("It's sat tune\n");
        freq=atoi(param[2]);
        symrate=atoi(param[3]);
        tuner_idx=atoi(param[1]);
        printf("freq:%d, symrate:%d, tuner_idx:%d\n", freq, symrate, tuner_idx);
        if(!strcmp(param[4], "FE_MOD_DVB")){
              mod=1;
        }else if(!strcmp(param[4], "FE_MOD_DVBS2")){
              mod=2;
        }else{
            printf("wrong modulation\n");
        }
        printf("mod:%d\n", mod);
    }else{
        printf("It's ter tune\n");
    }

 
    /*    
    for(i=0; i <= param_idx; i++){
        printf("%s\n", param[param_idx]);
    }*/
     
    free(cmds);
    for(i=0; i<8; i++){
        free(param[i]);
    } 
    /*for(i=0; i<8; i++){ 
        param[i]=NULL;
    }
    free(trunk);*/
    free(param);
}
