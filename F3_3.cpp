/*Esercizio F3_3
    Scrivere un programma C++ che acquisisce da tastiera il numero intero non
    negativo n < 30 e stampa sul video la sommatoria dei binomiali n su k con k=0:n
*/

#include <cstdio>

int main(void){
    int n; double bin = 1, som = 2; //la sommatoria parte da 2 perchè contiene già i valori per k = 0 e k = n
    printf("Inserire n intero positivo: ");
    scanf("%d", &n);
    if (n < 0 || n >= 30) {printf("\nIl numero inserito è invalido");return 1;}

    if (n == 0){printf("la sommatoria dei binomiali %d su k con k da 0 a %d è %d", n, n, 1);return 0;}   //se è uguale a 0 stampa direttamente 1
    for (int i = 1; i < n; i++){        //non calcolo né primo né ultimo termine
        for (int j = 1; j <= n-i; j++) bin *= (i+j)/j;  //annido un altro for per calcolare per ogni i il binomiale corrispondente
        som += bin;
        bin = 1;
    }
    printf("la sommatoria dei binomiali %d su k con K da 0 a %d è %.0f", n, n, som);
    return 0;
}