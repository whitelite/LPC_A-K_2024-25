/*Esercizio F10_3
    Considerare f (x) = log x + x. Scrivere un programma che acquisisce due reali a
    e b, con a < b che saranno usati per l’inizializzazione del metodo delle secanti per
    l’approssimazione di ξ; successivamente stampa sul video il numero k di iterazioni
    compiute dal metodo delle secanti per approssimare ξ con errore minore di 10−5
    (preventivando al massimo 100 iterazioni) e il valore approssimato di ξ fornito dal
    metodo.
*/

#include <cmath>
#include <cstdio>
#define TOL 1.e-5
#define MAXIT 100

double funzione( double);

int secanti(double, double&, double);

int main(void){
    double a, b; int iter;
    do{
    printf("Inserire il primo valore per l'iniziallizzazione a: ");
    scanf("%lf", &a);
    printf("Inserire il secondo valore per l'inizializzazione b: ");
    scanf("%lf", &b);
    if(b < a)
        printf("\nDati non validi. Reinserirli\n");}
    while( b < a);

    iter = secanti(a, b, TOL);

    printf("Soluzione approssimata dal metodo delle secanti con precisione 10^-5 --> %.13lf\nIterazioni del metodo eseguite --> %d\n", b, iter);
    return 0;

}

double funzione(double x){
    return log(x) + x;
}

int secanti(double x_0, double& x_1, double tau){
    int cont = 0; double delta, fx_0, fx_1;
    fx_0 = funzione(x_0);                           //valuto la funzione in x_0 una sola volta fuori, il resto delle volte passo il valore di x_1
    do{
        fx_1 = funzione(x_1);                       //valuto ogni volta f in x_1, calcolo la differenza, passo il valore di x_1 a x_0 e calcolo il nuovo x_1
        delta = fx_1/(fx_1 - fx_0)*(x_1 - x_0);
        x_0 = x_1;
        x_1 -= delta;
        fx_0 = fx_1;                                //passo il valore di fx_1 a fx_0 e ricomincio fino ad aver soddosfatto il criterio d'arresto
    }while(++cont < MAXIT &&(delta >= tau || delta <= -tau));
    return cont;
}