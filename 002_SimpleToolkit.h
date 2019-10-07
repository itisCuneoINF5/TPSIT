/*
Autore: Giovanni Giorgis
Titolo: Implementazione di un toolkit semplice
Desccrizione: data una semplicissimo record formato da un char e un int creaare il relativo toolkit
*/

#include <string.h>
#include <assert.h>
#ifndef CASACCIO_H_INCLUDED
#define CASACCIO_H_INCLUDED

typedef struct
{
    int a;
    char c;
} Casaccio;

char** str_split(char* a_str, const char a_delim);
Casaccio* crea(int a, char c);
Casaccio* creaSP();
Casaccio * creaS(char *s);
/*Casaccio * crea(FILE * file);*/
void distruggi(Casaccio *c);
int getA(Casaccio * c);
char getC(Casaccio * c);
void setA(int a, Casaccio *c);
void setC(char cara, Casaccio *c);
char * toString(Casaccio *c);


/*Funzione che riceve 2 parametri e istanzia un Casaccio restituendo
il puntatore*/
Casaccio* crea (int a, char c)
{

    Casaccio* casacccio;
    casacccio = (Casaccio *)malloc(sizeof(Casaccio));
    casacccio->a = a;
    casacccio->c = c;
    return  casacccio;
}

/*Funzione che riceve nessun paratro e istanzia un Casaccio*/
Casaccio* creaSP()
{

    Casaccio* casaccio = (Casaccio *)malloc(sizeof(Casaccio));
    casaccio->a = 0;
    casaccio->c = 'a';

    return casaccio;
}

/*funzione che dealloca lo spazio utilizzato dalla malloc*/
void distruggi(Casaccio *c)
{

    printf("Sto liberando lo spazio occupato da Casaccio\n");
    free(c);
}

/*Getter della struttura casaccio*/
int getA(Casaccio * c)
{

    int a = c->a;
    return a;
}
char getC(Casaccio * c)
{

    char carattere = c->c;
    return carattere;
}

/*setter della struttura Casaccio*/
void setA(int a, Casaccio *c)
{
    c->a = a;
}
void setC(char cara, Casaccio *c)
{
    c->c = cara;
}

/*funzione che serializza i valori dell struttura*/
char * toString(Casaccio *c)
{

    char str[1000];
    sprintf(str, "intero : %d char: %c \n",10, 'd' );
    return strdup(str);
}

Casaccio * creaS(char *s)
{
    char** campi;
    campi = str_split(s, ',');

    printf("split eseguita con successo, %c %c \n ",*campi, *(campi++));

    Casaccio* casaccio = crea(atoi(*campi), **(campi++));
    return casaccio;

}


char** str_split(char* a_str, const char a_delim) //funzione che restituisce un vettore di stringhe(puntatore a array di puntatori)
{
    printf("entro nella split, ho rievuto la stringa %s", a_str);
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

    printf("1");
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
        printf("2");
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    printf("arrivato alla fine della split ecco il result %s %s ", *result, *(result++));
    return result;
}
/*
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
*/

#endif // CASACCIO_H_INCLUDED

