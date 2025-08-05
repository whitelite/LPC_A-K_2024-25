/*Esercizio F4_3
    Scrivere un programma C++ che acquisisce da tastiera un numero reale x e un
    numero intero n. Se n non è negativo, calcola e stampa sul video xn , altrimenti
    (ovvero se n è negativo), stampa sul video inf nel caso che x è “zero”, o calcola
    e stampa sul video 1/x−n altrimenti (ovvero nel caso che x è diverso da “zero”).
    In tutti i casi si confronta con l’output dato dalla funzione ‘pow’ chiamata con
    argomenti x e n.

*/

#include <cstdio>
#include <cmath>
#define TOL 2.2e-16       //epsilon di macchina in double


int main(void){
    double x, pot = 1; int n;
    
    printf("Inserire un numero reale:  ");
    scanf("%lf", &x);
    printf("Inserire un numero intero: ");
    scanf("%d", &n);
    
    switch(n >= 0){                                                 //switch che controlla se n è negativo o meno e fa di conseguenza
        case 1: for (int i = 1; i <= n; i++) pot *= x; break;
        case 0: if(x < TOL && x > -TOL) {pot = INFINITY; break;}
                for (int i = 1; i <= -n; i++) pot *= 1/x; break;
    }
    printf("\n%lf\n\n", pot);
    printf("Confronto con pow:\n programma -->  %lf\n pow       -->  %lf\n", pot, pow(x, n));
    return 0;

}