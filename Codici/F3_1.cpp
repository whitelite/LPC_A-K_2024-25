/*Esercizio F3_1
    Scrivere un programma C++ che acquisisce da tastiera un numero intero non
    negativo k, controlla che non sia stato inserito un numero negativo (altrimenti ne
    cambia segno) e ne stampa sul video il fattoriale. Ricordare che, per convenzione,
    il fattoriale di 0 vale 1.
*/

#include <cstdio>

int main(void){

    int k; double fatt = 1; //lo salvo in un double per evitare integer overflow dato l'andamento del fattoriale
    printf("Inserire il numero di cui si vuole calcolare il fattoriale: ");
    scanf("%d", &k);
    if (k<0) k = -k;   //moltiplica k per -1 se non è positivo
    for (int i = 2; i<=k; i++) fatt*=i; //parto da 2 perchè per 0 ed 1 vale 1, quindi sono passi inutili se pongo fatt=1
    printf("%d! = %.0f\n", k, fatt);    //lo stampo con 0 cifre dopo la virgola perchè è sicuramente intero
    return 0;
}
