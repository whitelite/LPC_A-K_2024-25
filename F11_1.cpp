/*Esercizio F11_1
    Scrivere un programma C++ strutturato in funzioni che acquisisce da tastiera il
    numero reale x ∈ [−1, 1], stampa il valore ex e calcola - con il criterio di arresto a
    posteriori discusso a lezione - il grado necessario a garantire che l’approssimazione
    fornita dal polinomio di Taylor di e|x| , con x0 = 0, abbia almeno precisione 10−10 ;
    successivamente stampa sul video l’approssimazione di ex ottenuta facendo uso del
    polinomio di Taylor costruito per l’approssimazione di e|x| (se x < 0, stampandone
    quindi il reciproco) e il suo grado effettivo. Testare il programma con x = −0.9 e
    x = 0.1.
*/

#include <cmath>
#include <cstdio>
#define TOL 1.e-10

int exp_T(double& x, double tau);

double input();

int main(void){
    double x, val; int grad;
    x = input();

    val = exp(x);

    printf("exp(x) --> %.13lf", val);

    grad = exp_T(x, TOL);
    printf("\nGrado necessario per approssimare exp(x) con x in [-1, 1] del polinomio di Taylor centrato in 0 --> %d", grad - 1);           //perchè il criterio di arresto in realtà arresta le iterazioni ad un termine in più del necessario e quindi basta sottrarre 1 al grado effettivo del polinomio
    printf("\nApprossimazione con tolleranza %e di exp(x) con polinomio di Taylor centrato in 0 di grado %d --> %.13lf\n", TOL, grad, x);

    return 0;
}

int exp_T(double& x, double tau){
    int s = 0, cont = 0; double fact = 1, pot = 1, delta, somma = 1;
    tau /= M_E;                 //divido all'inizio la tolleranza così da non dover ripetere l'operazione ad ogni iterata
    if (x < 0) {s = 1; x = -x;} //memorizza il segno di x, che verrà considerato successivamente per valutare se serve fare il reciproco
    do{
        fact *= ++cont;
        pot *= x;
        delta = pot/fact;
        somma += delta; 
    }while(delta >= tau);
    
    if(s){x = 1/somma;}
    else{x = somma;}
    
    return cont;
    
}

double input(){
    double in;
    do{
        printf("Inserire un numero reale x ( -1 <= x <= 1): ");
        scanf("%lf", &in);
        if(in < -1 || in > 1)
            printf("Numero non valido, reinserire.\n");
    }
    while(in < -1 || in > 1);
    return in;
}