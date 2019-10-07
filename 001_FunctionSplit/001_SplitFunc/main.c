#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim) //funzione che restituisce un vettore di stringhe(puntatore a array di puntatori)
{
    char** result    = 0; //crea ciò che poi restituiremo
    int count     = 0; //inizalizza un contatore
    char* tmp        = a_str; //fonddamentale per scorrere la stringa e non  perdere il puntatorre a quella
    char* last_comma = 0; //puntatore all'  ultima virgola
    char delim[2]; //vettore di char
    delim[0] = a_delim;
    delim[1] = 0;

    /* Conta quanti elementi dovranno essere estratti e mette il numero nel contatore  */
    while (*tmp) // per scorrere una stringa
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        int idx  = 0;
        char* token = strtok(a_str, delim);


        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(NULL, delim);

        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int main()
{
    char months[] = "GEN,FEB,MAR,MAG,GIU,LUG,AGO,SET";
    char** tokens;

    printf("months=[%s]\n\n", months);

    tokens = str_split(months, ',');

    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("month=[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }

    return 0;
}
