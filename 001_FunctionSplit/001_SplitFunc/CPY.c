#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char ** split(char * str, const char sepa){

    char ** result = 0;
    char * tmp = str;
    int count = 0;
    char * last_comma = 0;
    char separa[2];
    separa[0] = sepa;
    separa[1] = 0;

    while(*tmp){
        if (*tmp = sepa){
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (str + strlen(str)-1);
    count ++;

    result = malloc(sizeof(char*)*count);

    if(count){

        int idx = 0;
        char* token = strtok(str, separa);
        while(token){
            assert(idx < count);
            *(result+idx++)=strdup(token);
            token = strtok(NULL, separa);
        }
        *(result+idx++)=0;
    }
    return result;

}
