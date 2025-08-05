/*Esercizio F4_4
    Scrivere un programma C++ che calcola e stampa sul video la seguente approssi-
    mazione del numero di Nepero e ne stampa sul video l’errore relativo facendo uso 
    della costante ‘M_E’.
*/

#include <math.h>
#include <cstdio>

int main(void){
    double e = 1, fat = 1; int k = 1;  //esculdo il primo termine della sommatoria che so già che vale per rende più lineare il codice
    do{
        fat *= k;
        e += 1/fat;              
    }while(++k<=16);
    
    printf("Errore relativo di approssimazione rispetto a M_E --> %.16f\n\ne approssimato --> %.16f\nM_E            --> %.16f\n", (e - M_E)/M_E, e, M_E);
}