/*
Autore: Giovanni Giorgis
Titolo: Implementazione di una struttura a Casaccio
Data: 7/10/2019
Descrizione: Data una semplice struttura Casaccio, composta da un intero e da un char
            implementarne il toolkit
*/
#include <stdio.h>
#include <stdlib.h>

#include "casaccio.h"

int main()
{
    //controllo della prima funzione del toolkit Casaccio
    Casaccio* casa = crea(7, 'a');
    printf("Prima funzione Casaccio* crea %d %c \n", casa->a, casa->c);

    //controllo dellaa seconda funzione crea senza paramtri
    Casaccio* casa2 = creaSP();
    printf("Seconda funzione Casaccio* crea %d %c \n", casa2->a, casa2->c);

    //controllo dei getter
    printf("%d %c \n", getA(casa), getC(casa));

    setA(100, casa2);
    setC('z', casa2);
    printf("funzioni setter su Casaccio*, nuovi valori = %d %c \n", casa2->a, casa2->c);

    //controllo del serializzatore
    printf("%s \n", toString(casa2));

    //controllo con creazione da string
    Casaccio* casa3 = creaS("12,d");
    printf("Terza Casaccio* crea %d %c \n", casa3->a, casa3->c);


    //controlliamo che il distruttore funzioni
    distruggi(casa);
    distruggi(casa2);

    return 0;

}
