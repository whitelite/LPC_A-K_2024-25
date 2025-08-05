/*Esercizio F5_2 
    Scrivere un programma C++ che acquisisce da tastiera un numero reale r != 1 e
    un intero non negativo n, stampa sul video la somma sn (r) = 1 + r + r2 + · · · + rn
    dei primi n + 1 termini della progressione geometrica di ragione r come da consegna.
    Testare il programma calcolando s5 (−3.5)

*/

#include <cstdio>

int main(void){
    int n = 1; double r, pot = 1, somma = 1, check;         //la somma parte da 1 così non considero il caso per n = 0
    printf("Inserire un numero reale diverso da 1 :");      //allo stesso tempo il ciclo si ferma immediatamente se n = 0 e quindi somma = 1 = r^0
    scanf("%lf", &r);
    if (r == 1) {printf("\nNumero non valido\n"); return 1;}
    printf("\nInserire un numero intero non negativo :");
    scanf("%d", &n);
    if ( n < 0) {printf("\nNumero non valido\n"); return 1;}
    while(n-- > 0){
        pot *= r;
        somma += pot;}
    check = (1 - pot * r)/(1 - r);      //lo moltiplico per r e ottengo r^n+1 perchè pot alla fine del ciclo già vale r^n
    printf("Successione calcolata iterativamente     --> %lf\nSuccessione calcolata con formula chiusa --> %lf\n", somma, check);
    return 0;
}