/* Esercizio F1_3

    Prima parte:
    Programma che acquisisce da tastiera due numeri interi, rispettivamente
    base e altezza di un rettangolo, e, se sono entrambe positivi,
    stampa sul video perimetro e area del rettangolo, altrimenti stampa
    un messaggio d'errore

    Seconda parte:
    test con valori a=2147483647    b=1 
    e valori        a=2147483648    b=1

*/

#include <stdio.h>

int main(void){

    //Prima parte
    float base, altezza;
    printf("Fornire base e altezza del rettangolo(separati da uno spazio): ");
    scanf("%f %f", &base, &altezza);
    //scanf("Altezza: %f\n", &altezza);
    if(base < 0 || altezza < 0){printf("Inserire valori positivi"); return 1;} else{printf("Area: %f\nPerimetro: %f", base*altezza, (base+altezza)*2.); return 0;};
    //la riga sopra controlla il segno di base e altezza e opera di conseguenza come da consegna

}