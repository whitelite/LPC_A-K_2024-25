/*Esercizio F5_4
    Scrivere un programma C++ che acquisisce da tastiera un numero decimale intero
    positivo, lo converte in base binaria, e stampa sul video il risultato ottenuto.
*/

#include <cstdio>
#define N 31            //mi bastano 31 cifre perchè il massimo intero positivo con int è 2^31-1

int main(void){
    int dec, bin[N], ind = 0;
    printf("Inserire un numero decimale intero positivo: ");
    scanf("%d", &dec);
    
    while(dec){                                 //divido dec fino a che vale 0...
        bin[ind++] = dec % 2;                   //... e incremento il contatore
        dec /= 2;
    }
    
    printf("\nIl numero convertito in base binaria --> ");
    
    while(ind)printf("%d", bin[--ind]); printf("\n");      //stampo solo le cifre che ho calcolato in ordine decrescente
    
    return 0;
}