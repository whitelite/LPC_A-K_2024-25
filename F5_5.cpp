/*Esercizio F5_5
    Scrivere un programma C++ che acquisisce da tastiera un numero intero n tale
    che 0 ≤ n < 10, i coefficienti a0 , a1 , ..., an di un polinomio pn e un numero reale x;
    calcola con l’algoritmo di Horner il valore pn (x); stampa pn (x) sul video. Testare
    il programma calcolando la medesima somma s5 (−3.5) calcolata nell’Esercizio 2.
*/

#include <cstdio>
#define N 10

int main(void){
    double coef[N], x, y; int n;
    do{                                                                                 //input dei dati
        printf("Inserire il grado del polinomio da valutare (0 <= n <= 9): ");
        scanf("%d", &n);
    }while(n < 0 || n >= N);
    printf("Inserire i %d coefficienti del polinomio:\n ", n+1);
    for (int i = 0; i <= n; i++){
        printf("a_%d = ", i);
        scanf("%lf", &coef[i]);
    }
    printf("Inserire il valore x in cui si vuole valutare il polinomio: ");
    scanf("%lf", &x);

    y = x*coef[n];                          //polinomio valutato secondo lo schema di Horner
    for (int i = n-1; i > 0; i--){
        y += coef[i];
        y *= x;
    }
    y += coef[0];

    printf("p(x) --> %lf\n", y);
    return 0;

}