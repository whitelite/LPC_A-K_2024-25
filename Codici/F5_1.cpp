/*Esercizio F5_1
    Scrivere un programma
    C++ che implementa l’algoritmo di Erone per l’appros-
    simazione di radice di 2. Fissare a 1.e − 12 la massima tolleranza per l’errore assoluto e
    stampare sul video le approssimazioni calcolate in ogni iterazione visualizzando-
    ne sedici cifre significative. Confrontare l’approssimazione finale con la costante
    ‘M_SQRT2’.

*/

#include <cstdio>
#include <cmath>
#define TOL 1.e-12

int main(void) {
    double x = 2, temp; int i = 0;
    do{
        temp = x;                       //calcola radice di 2 secondo l'algoritmo di erone
        x = (x+2/x)/2;
        i++;
        printf("%.15lf alla %d iterazione\n", x, i);     //è %.15 perchè la prima cifra intera conta come cifra significativa
    }while(temp - x > TOL);
    printf("M_SQRT2 --> %.15lf\n", M_SQRT2);
    return 0;

}