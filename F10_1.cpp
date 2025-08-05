/*Esercizio F10_1
    Considerare f (x) = log x + x. Scrivere un programma che acquisisce due reali a
    e b, con a < b, che rappresentano gli estremi di un intervallo nel quale lo zero
    semplice ξ delle funzione assegnata è stato precedentemente localizzato e separato
    (avvalendosi eventualmente dell’aiuto di gnuplot) e stampa sul video sia il numero
    di iterazioni del metodo di bisezione necessarie a garantire una approssimazione di
    ξ con errore minore di 10−5 che il valore approssimato di ξ fornito dal metodo.
*/

#include <cmath>
#include <cstdio>
#define TAU 1.e-5



double funzione(double);

double modd(double n);

double bisezione(double, double, int, double);

int iterazioniB(double, double, double);


int main(void){
    double a, b, sol; int iter;
    do{
    printf("Inserire l'estremo sinistro dell'intervallo: ");
    scanf("%lf", &a);
    printf("Inserire l'estremo destro dell'intervallo: ");
    scanf("%lf", &b);
    if(b < a)
        printf("\nDati non validi. Reinserirli\n");}
    while( b < a);

    iter = iterazioniB(a, b, TAU);
    sol = bisezione(a, b, iter, TAU);
    
    printf("\nIterazioni necessarie ad una soluzione nella tolleranza di 10^-5 --> %d\nApprosimazione della soluzione --> %lf\n", iter, sol);

    return 0;

}






double funzione(double x){
    return log(x)+x;
}

double modd(double n){
    return (n < 0)? -n : n;
}
double bisezione(double a, double b, int iter, double tau){
    double fa = funzione(a);
    if (fa > -tau && fa < tau) return a;        //se a approssima xi bene secondo la tolleranza, allora la restituisce come approssimazione
    double fb = funzione(b);
    if (fb > -tau && fb < tau) return b;        //idem per b
    double mid = (a+b)/2, fmid;
    for(int i = 0; i < iter; i++){
        fmid = funzione(mid);
        if (fmid > -tau && fmid < tau) return mid;          //controlla che la soluzione sia nella tolleranza per evitare problemi dovuti alla velocità di convergenza
        if (fa*fmid < 0)
            {b = mid; fb = fmid;}                             //calcola il nuvo estremo del sottointervallo
        else
            {a = mid; fa = fmid;}
        mid = (a+b)/2;
    }
    return mid;                 //restiruisce l'approssimazione
}

int iterazioniB(double a, double b, double tau){
    return log2(modd(b-a)/tau);
}