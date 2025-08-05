/*Esercizio F5_6
Scrivere un programma C++ che stampa i numeri primi fino a n ≤ 1000 usando
il crivello di Eratostene
*/

#include <cstdio>
#define N 1000

int main(void){
    int n;

    do{
        printf("Inserire un numero intero n ( 0 <= n <= 1000): ");
        scanf("%d", &n);
    }while(n < 0 || n > N);

    int crivello[n+1];              //inizializzo il vettore dopo dato che il numero di elementi massimo è molto grande
    
    for (int i = 0; i<= n; i++)     //lo inizializzo tutto a 1
        crivello[i] = 1;

    for (int i = 2; i*i <= n; i++)      //applico il criterio del crivello di Eratostene
        if (crivello[i])
            for (int j = i*i; j<= n; j += i)
                crivello[j] = 0;
    
    printf("I numeri primi fino a %d sono: \n", n);     //stampo gli indici degli elementi non nulli
    for (int i = 2; i <= n; i++)
        if(crivello[i])
            printf("%d ", i);
    
    return 0;

}