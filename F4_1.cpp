/*Esercizio F4_1
    Scrivere un programma C++ che acquisisce da tastiera i coefficienti reali a, b, c
    di una equazione di secondo grado ax2 + bx + c = 0, controlla che a sia diverso
    da “zero” (altrimenti termina con un messaggio di errore), calcola le radici reali
    e distinte dell’equazione (con un algoritmo stabile) e le stampa sul video, oppure
    segnala che non ci sono radici reali e distinte.
*/


#include <cstdio>
#include <cmath>
#define TOL 2.2e-16 //cioè la epsilon di macchina in doppia precisione

int main(void){
    double a,b,c,delta,x1,x2;
    printf("Primo coefficiente:     a = ");
    scanf("%lf", &a);
    if (a > -TOL && a < TOL) { printf("L'equazione data non è di secondo grado \n"); return 1;} //controlla se a è uguale a 0
    printf("Secondo coefficiente:   b = ");
    scanf("%lf", &b);
    printf("Terzo coefficiente:     c = ");
    scanf("%lf", &c);
    delta = b*b-4*a*c;
    if (delta<TOL)      //se delta è minore di 0 allora non ci sono radici reali distinte
        printf("Non ci sono due radici reali distinte");
    //due casi distinti per il segno di b, che può creare problemi
    else if (b<0){
        delta = sqrt(delta);
        x1 = (-b+delta)/(2*a);  //calcolo usuale perchè sommiamo -b e delta (entrambe positivi)
        x2 = 2*c/(-b+delta);    //calcolo ottimizzato perchè altrimenti si rischia cancellazione numerica
        printf("Prima radice    =%e\n", x1);
        printf("Seconda radice  =%e\n", x2);
    }
    else{
        delta = sqrt(delta);
        x2 = (-b-delta)/(2*a);  //calcolo usuale perchè sommiamo -b e -delta (entrambe negativi)
        x1 = 2*c/(-b-delta);    //calcolo ottimizzato perchè altrimenti si rischia cancellazione numerica
        printf("Prima radice    =%e\n", x1);
        printf("Seconda radice  =%e\n", x2);
    }
    return 0;
}

