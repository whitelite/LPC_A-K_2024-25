/*Esercizio F10_2
    Considerare f (x) = log x + x. Scrivere un programma che acquisisce due reali a e
    b, con a < b (estremi dell’intervallo nel quale ξ è stato precedentemente localizzato
    e separato) e l’estremo di Fourier, che rappresenta l’approssimazione iniziale di ξ;
    successivamente stampa sul video il numero di iterazioni compiute dal metodo di
    Newton per approssimare ξ con errore minore di 10−5 (preventivando al massimo
    100 iterazioni) e il valore approssimato di ξ fornito dal metodo.
*/

#include <cmath>
#include <cstdio>
#define TOL 1.e-5
#define MAXIT 100


double funzione(double);

double derivata(double);

int newton(double&, double);




int main(void){
    double a, b, sol, f; int iter;
    do{
    printf("Inserire l'estremo sinistro dell'intervallo a: ");
    scanf("%lf", &a);
    printf("Inserire l'estremo destro dell'intervallo b: ");
    scanf("%lf", &b);
    printf("Indicare l'estremo di Fourier (1 => a, 2 => b): ");
    scanf("%lf", &f); f-=1; f = (int) f;
    if(b < a || f < 0 || f > 1)
        printf("\nDati non validi. Reinserirli\n");}
    while( b < a || f < 0 || f > 1);

    //al posto di acquisirlo nuovamente basta selezionarlo tra i due inseriti prima
    f = (f)? b : a;
    iter = newton(f, TOL);

    printf("Soluzione approssimata dal metodo di Newton con precisione 10^-5 --> %.13lf\nIterazioni del metodo eseguite --> %d\n", f, iter);
    return 0;

}



double funzione(double x){
    return log(x) + x;
}

double derivata(double x){
    return 1+1/x;         
}

int newton(double& x, double tau){
    int cont = 0; double delta;
    do{
        delta = funzione(x)/derivata(x);        //questo delta equivale a x_i - x_(i-1), che ci consente di utilizzare il criterio d'arresto praticamente con 1 solo controllo e nessun operazione in più
        x -= delta;
    }while(++cont < MAXIT &&(delta >= tau || delta <= -tau));
    return cont;
}