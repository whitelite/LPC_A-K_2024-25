/*Esercizio F3_4
    Scrivere un programma C++ che acquisisce da tastiera due numeri interi m e n
    non nulli (se non vengono rispettate queste restrizioni nell’immissione da parte del-
    l’utente, il programma termina con un messaggio opportuno) e ne stampa sul video
    sia il massimo comune divisore, calcolato con l’algoritmo di Euclide delle divisioni
    successive, che il minimo comune multiplo, calcolato osservando che quest’ultimo
    equivale al rapporto tra il loro prodotto e il loro massimo comune divisore.
*/


#include <cstdio>

int main(void){

    int m, n, mcd, r, d;
    printf("Inserire il numero intero non negativo m: ");
    scanf("%d", &m);
    printf("Inserire il numero intero non negativo n: ");
    scanf("%d", &n);
    if(m < 0 || n < 0) {printf("Numeri invalidi"); return 1;}   //controlla 
    mcd=m; d=n;
    do{
        r = mcd % d;  //il resto è uguale a mcd%d
        mcd = d;    //assegna il nuovo numero da dividere
        d = r;      //e assegna il nuovo divisore
        
    }
    while(r > 0);   //si arresta quando il resto è 0
    printf("Il loro MCD è %d, il loro mcm è %d", mcd, m*n/mcd); //restituisce MCD ed mcm
}