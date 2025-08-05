/*Esercizio F11_3
    Scrivere un programma C++ strutturato in funzioni che, definita la costante T ,
    stampa su video l’approssimazione di cos(T π) realizzata facendo uso del polinomio
    interpolatore determinato dalla tavola della funzione coseno relativa agli n0 + 1
    nodi di Chebyshev (*) associati all’intervallo [0, π/2]. Il grado n0 , che dipende
    da T ed è stato calcolato nell’esercizio precedente per due diverse tolleranze, deve
    essere inserito da tastiera.
    Confrontare l’output del programma con l’output del programma precedente nei
    casi T = 0.1 e T = 0.4, avendo inserito in entrambi i casi i due gradi n0 effettivi.
*/

#include <cstdio>
#include <cmath>
#define T 0.4



int input_g();

void nodiC(double, double, double[], int);

double p_inter_Lagrange(double, double[], int);

int main(void){

    int g = input_g();

    double nodi[g+1];

    nodiC(0., M_PI/2 , nodi, g);

    double y = p_inter_Lagrange(T, nodi, g);

    printf("Approssimazione con polinomio interpolatore utilizzando i nodi di Chebyshev --> %.16lf\nErrore --> %e\n", y, cos(T*M_PI) - y);
    return 0;


}






int input_g(){
    int n;
    do{
        printf("Inserire il grado del polinomio interpolatore: ");
        scanf("%d", &n);
        if (n < 0) printf("Reinserire.\n");
    }while(n < 0);
    return n;
}

void nodiC(double a, double b, double nodi[], int n){
    double h = (b+a)/2, m = (b-a)/2, c = M_PI/(2*n+2);      //calcolo questi coefficienti all'inizio così da fare meno conti ad ogni iterazione

    for (int i = 0; i <= n; i++)
        nodi[i] = h + m*cos(c*(2*i+1));
    return;
} 

double p_inter_Lagrange(double x, double nodi[], int n){
    double l_i, p_x = 0; x *= M_PI;                              //approssimo la funzione coseno ma devo in realtà calcolare cos(T*pi)
    for(int i = 0; i <= n; i++){
        l_i = 1;
        for (int j = 0; j <= n; j++)
            if(i != j)                                          //controlla che i nodi non siano uguali
                l_i *= (x-nodi[j])/(nodi[i]-nodi[j]);           //calcola il polinomio fondamentale riferito a ogni nodo
        p_x += cos(nodi[i]) * l_i;                              //calcola il polinomio interpolatore in forma di Lagrange che approssima la funzione coseno
    }
    return p_x;
}