/* Esercizio F1_2  

    Programma che acquisisce un numero reale da tastiera 
    della misura di un angolo in gradi, lo converte in radianti,
    ne calcola seno e coseno e li stampa sul video


*/

#include <stdio.h>
#include <math.h>

int main(void){

    float misura, seno, coseno;
    printf("Misura dell'angolo in gradi: ");
    scanf("%f", &misura);               //legge la misura in gradi
    misura = misura * M_PI / 180;       //la converte

    //calcola seno e coseno
    seno = sin(misura);
    coseno = cos(misura);
    
    //stampa i risultati
    printf("Misura dell'angolo in radianti: %f\nSeno: %f\nCoseno: %f", misura, seno, coseno);
    return 0;
}