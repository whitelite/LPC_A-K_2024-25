/*Esercizio F10_2
    Considerare f (x) = log x + x. Scrivere un programma che acquisisce due reali a e
    b, con a < b (estremi dell’intervallo nel quale ξ è stato precedentemente localizzato
    e separato) e l’estremo di Fourier, che rappresenta l’approssimazione iniziale di ξ;
    successivamente stampa sul video il numero di iterazioni compiute dal metodo di
    Newton per approssimare ξ con errore minore di 10−5 (preventivando al massimo
    100 iterazioni) e il valore approssimato di ξ fornito dal metodo.
*/
    
    /* MODIFICATO PER L'ESERCIZIO 4 */

#include <cmath>
#include <cstdio>
#define TOL 1.e-13
#define MAXIT 100



double funzione(int, double);

double derivata(int, double);

int newton(double&, double, double, int);

int main(void){
    double a, b, x, sol, f; int iter, s;
    do{
    printf("Selezionare una funzione\n");
    printf("1 = x^3+2y^3 = 3xy\n");
    printf("2 = x^5 - 6x^3 + 3\n");
    printf("3 = x - e^(-x)\n");
    printf("4 = x^2 - sin(x)\n");
    printf("5 = x - cos(x)\n");
    printf("6 = x^2 - 2 - log(x)\n");
    printf("Selezione: ");
    scanf("%d", &s);
    printf("\nInserire l'estremo sinistro dell'intervallo a: ");
    scanf("%lf", &a);
    printf("Inserire l'estremo destro dell'intervallo b: ");
    scanf("%lf", &b);
    printf("\nIndicare l'estremo di Fourier (1 => a, 2 => b): ");
    scanf("%lf", &f); f-=1; f = int(f);
    printf("\nInserisci il valore di x = ");
    scanf("%lf", &x);
    if(b < a || f < 0 || f > 1 || s < 1 || s > 6)
        printf("\nDati non validi. Reinserirli\n");}
    while( b < a || f < 0 || f > 1 || s < 1 || s > 6);

    //al posto di acquisirlo nuovamente basta selezionarlo tra i due inseriti prima
    f = (f)? b : a;
    iter = newton(f, x, TOL, s);

    printf("Soluzione approssimata dal metodo di Newton con precisione %e --> %.14lf\nIterazioni del metodo eseguite --> %d\n",TOL, f, iter);
    return 0;

}




double funzione(int s, double y, double x){
    
    switch(s){
        case 1: return (x*x*x+5*y*y*y-3*x*y); break;
        case 2: return (x*x*x*(x*x - 6))+3; break;
        case 3: return x - (1/exp(x)); break;
        case 4: return x*x - sin(x); break;
        case 5: return x - cos(x); break;
        case 6: return x*x - 2 - log(x); break;
    }
    return 1;
}

double derivata(int s, double y, double x){

    switch(s){
        case 1: return 15*y*y-3*x; break;
        case 2: return (x*x*(5*x*x - 18)); break;
        case 3: return 1 + (1/exp(x)); break;
        case 4: return 2*x - cos(x); break; 
        case 5: return 1 + sin(x); break;
        case 6: return 2*x - (1/x); break;
    }  
    return 1;       
}

int newton(double& y, double x,  double tau, int s){
    int cont = 0; double delta;
    do{
        delta = funzione(s, y, x)/derivata(s, y, x);        //questo delta equivale a x_i - x_(i-1), che ci consente di utilizzare il criterio d'arresto praticamente con 1 solo controllo (e della memoria occupata) e nessun operazione in più 
        y -= delta;
    }while(++cont < MAXIT &&(delta >= tau || delta <= -tau));
    return cont;
}