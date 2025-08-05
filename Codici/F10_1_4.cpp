/*Esercizio F10_1
    Considerare f (x) = log x + x. Scrivere un programma che acquisisce due reali a
    e b, con a < b, che rappresentano gli estremi di un intervallo nel quale lo zero
    semplice ξ delle funzione assegnata è stato precedentemente localizzato e separato
    (avvalendosi eventualmente dell’aiuto di gnuplot) e stampa sul video sia il numero
    di iterazioni del metodo di bisezione necessarie a garantire una approssimazione di
    ξ con errore minore di 10−5 che il valore approssimato di ξ fornito dal metodo.
*/

    /* MODIFICATO PER L'ESERCIZIO 4 */

#include <cmath>
#include <cstdio>
#define TAU 1.e-5


double funzione(int, double);

double modd(double n);

double bisezione(double, double, int, double, int);

int iterazioniB(double, double, double);

int main(void){
    double a, b, sol; int iter, s;
    do{
    printf("Selezionare una funzione\n");
    printf("1 = x^2 - 2\n");
    printf("2 = x^5 - 6x^3 + 3\n");
    printf("3 = x - e^(-x)\n");
    printf("4 = x^2 - sin(x)\n");
    printf("5 = x - cos(x)\n");
    printf("6 = x^2 - 2 - log(x)\n");
    printf("Selezione: ");
    scanf("%d", &s);
    printf("Inserire l'estremo sinistro dell'intervallo: ");
    scanf("%lf", &a);
    printf("Inserire l'estremo destro dell'intervallo: ");
    scanf("%lf", &b);
    if(b < a || s < 1 || s > 6)
        printf("\nDati non validi. Reinserirli\n");}
    while( b < a || s < 1 || s > 6);

    iter = iterazioniB(a, b, TAU);
    sol = bisezione(a, b, iter, TAU, s);
    
    printf("\nIterazioni necessarie ad una soluzione nella tolleranza di 10^-5 --> %d\nApprosimazione della soluzione --> %lf\n", iter, sol);

    return 0;

}







double funzione(int s, double x){                       //scelta della funzione
    
    switch(s){
        case 1: return (x*x-2); break;
        case 2: return (x*x*x*(x*x - 6))+3; break;
        case 3: return x - (1/exp(x)); break;
        case 4: return x*x - sin(x); break;
        case 5: return x - cos(x); break;
        case 6: return x*x - 2 - log(x); break;
    }
    return 1;
}

double modd(double n){
    return (n < 0)? -n : n;
}

double bisezione(double a, double b, int iter, double tau, int s){
    double fa = funzione(s, a);
    if (fa > -tau && fa < tau) return a;        //se a approssima xi bene secondo la tolleranza, allora la restituisce come approssimazione
    double fb = funzione(s, b);
    if (fb > -tau && fb < tau) return b;        //idem per b
    double mid = (a+b)/2, fmid;
    for(int i = 0; i < iter; i++){
        fmid = funzione(s, mid);
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