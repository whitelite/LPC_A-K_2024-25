/* Esercizio F2_3:
    Scrivere un programma C++ che acquisisce da tastiera un numero intero positivo
    n e calcola e stampa i primi n numeri della sequenza di Fibonacci.
    n deve essere minore di 47 per evitare un integer overflow
*/

#include <cstdio>

int main(void){

    int n, f_1 = 0, f_2 = 0, f;
    printf("Scegliere che numero di Fibonacci calcolare (massimo 46-esimo): ");    //prende il numero...
    scanf("%d", &n);
    if (n >= 47 || n <= 0){printf("\nNumero non calcolabile");return 1;}    //... e controlla se è calcolabile
    for (int i = 1; i<=n; i++){
            f = (i == 1) ? 1 : (i == 2) ? 1 : f_1 + f_2;    //controlla se è diverso da 1 e 2, altimenti lo calcola
            f_2 = f_1;
            f_1 = f;
    }
    printf("il %d° numero di Fibonacci è: %d\n", n, f);
    return 0;
}