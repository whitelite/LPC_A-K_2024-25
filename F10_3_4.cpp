/*Esercizio F10_3
    Considerare f (x) = log x + x. Scrivere un programma che acquisisce due reali a
    e b, con a < b che saranno usati per l’inizializzazione del metodo delle secanti per
    l’approssimazione di ξ; successivamente stampa sul video il numero k di iterazioni
    compiute dal metodo delle secanti per approssimare ξ con errore minore di 10−5
    (preventivando al massimo 100 iterazioni) e il valore approssimato di ξ fornito dal
    metodo.
*/

    /* MODIFICATO PER L'ESERCIZIO 4 */

#include <cmath>
#include <cstdio>
#define TOL 1.e-5
#define MAXIT 100



double funzione(int, double);

int secanti(double, double&, double, int);

int main(void){
    double a, b; int iter, s;
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
    printf("\nInserire il primo valore per l'iniziallizzazione a: ");
    scanf("%lf", &a);
    printf("Inserire il secondo valore per l'inizializzazione b: ");
    scanf("%lf", &b);
    if(b < a || s < 1 || s > 6)
        printf("\nDati non validi. Reinserirli\n");}
    while( b < a || s < 1 || s > 6);

    iter = secanti(a, b, TOL, s);

    printf("\nSoluzione approssimata dal metodo delle secanti con precisione 10^-5 --> %.13lf\nIterazioni del metodo eseguite --> %d\n", b, iter);
    return 0;

}


double funzione(int s, double x){
    
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

int secanti(double x_0, double& x_1, double tau, int s){
    int cont = 0; double delta, fx_0, fx_1;
    fx_0 = funzione(s, x_0);                                        //valuto la funzione in x_0 una sola volta fuori, il resto delle volte passo il valore di x_1
    do{
        fx_1 = funzione(s, x_1);                                    //valuto ogni volta f in x_1, calcolo la differenza, passo il valore di x_1 a x_0 e calcolo il nuovo x_1
        delta = fx_1/(fx_1 - fx_0)*(x_1 - x_0);
        x_0 = x_1;
        x_1 -= delta;
        fx_0 = fx_1;                                                //passo il valore di fx_1 a fx_0 e ricomincio fino ad aver soddosfatto il criterio d'arresto
    }while(++cont < MAXIT &&(delta >= tau || delta <= -tau));
    return cont;
}