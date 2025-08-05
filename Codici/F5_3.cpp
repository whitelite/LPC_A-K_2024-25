/*Esercizio F5_3
    Scrivere un programma C++ che acquisisce da tastiera un numero binario intero
    positivo che abbia al massimo 31 cifre, lo converte in base decimale, e stampa sul
    video il risultato ottenuto.    
*/

#include <cstdio>
/*Per motivi di distanza tra numeri di macchina, se salvassi un binario in double, non avrei cifre intere garantite (per numeri più grandi di 10^16), quindi mi limito a salvarlo come
intero, nonostante non potrò mai arrivare a 31 cifre, ma massimo 10. Mi semplifica notevolmente i calcoli*/
int main(void){
    int quoz, bin, dec = 0, pot = 1; 
    printf("Inserisci un numero binario intero positivo:");
    scanf("%d", &bin);
    
    while(bin){
        quoz = bin%10;                      //prende l'ultima cifra del numero, che in modulo 10 è il resto
        dec += quoz * pot; pot*= 2;         //aggiunge la corrispondete potenza di 2 alla rappresentazione decimale
        bin /= 10;                          //divide per 10, che siccome è divisione tra interi non considera la parte decimale.
    }
    printf("\nIl numero convertito in base decimale è : %d\n", dec);
    return 0;
 
}
