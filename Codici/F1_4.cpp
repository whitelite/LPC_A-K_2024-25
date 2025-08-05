/*Esercizio F1_4
    Scrivere un programma C++ che acquisisce da tastiera tre numeri reali e stampa
    sul video il massimo dei loro valori assoluti.
*/

#include <cstdio>

int main(void){
    double a, b, c;
    
    printf("Inserire tre nuemri reali.\na: ");      //prende i dati
    scanf("%lf", &a);
    
    printf("b: ");
    scanf("%lf", &b);
    
    printf("c: ");
    scanf("%lf", &c);
    
    if (a < 0) a = -a;       //calcola il valore assoluto dei tre reali
    if (b < 0) b = -b;
    if (c < 0) c = -c;

    if(a > b && a > c){;}       //confronta i dati
    else if( a < b){
        if(b < c){a = c;}
        else{ a = b;}
    }
    else if(a < c){
        if(c < b){a = b;}
        else{a = c;}
    }
    
    printf("Il massimo valore assoluto è %lf\n", a);    //stampa il valore assoluto massimo
    return 0;
}