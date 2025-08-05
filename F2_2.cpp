/* Esercizio F2_2

    Programma che acquisisce da tastiera la scelta dell'utente
    su quale media calcolare
    (1: aritmetica, 2: geometrica, 3: armonica, 4:quadratica)
    il numero n (che se non è positivo allora di default n=2)
    i reali positivi x_1:x_n 
    (se il numero è negativo, viene cambiato il segno, se è uguale a uno zero di macchina
    allora termina con un messaggio opportuno)
    infine stampa la media richiesta.
    Usare l'istruzione switch.
*/

#include <cstdio>
#include <cmath>

int main(void)
{
    int scelta, n; double x, M = 1;
    
    printf("Scegliere che media calcolare (1: aritmetica, 2: geometrica, 3: armonica, 4:quadratica): ");
    scanf("%d", &scelta);
    if(scelta < 1 || scelta > 4){printf("\nScelta non valida");return 1;} //controllo non richesto ma ho voluto metterlo lo stesso
    printf("\nInserire n naturale positivo: ");
    scanf("%d", &n);
    n = (n<=0) ? 2 : n; //mette n=2 se non è positivo, altrimenti lo lascia invariato
    for (int i = 1; i<=n; i++){
        printf("\nInserire x_%d --> ", i);
        scanf("%lf", &x);
        x = (x < 0) ? -x : x; //porta tutti i valori negati a positivi (anche gli zeri, mi semplifica il controllo successivo)
        if (x < 1.e-8){printf("\nx_%d è uguale a 0", i);return 1;} //controlla se è uno zero (minore della precisione di macchina), mi basta questo perchè ho solo valori positivi
        
        switch(scelta){ //in base alla scelta calcola la media corrispondente ( +1 tranne nel caso della media geometrica)
            case 1: M += x; break;
            case 2: M *= x; break;
            case 3: M += 1/x; break;
            case 4: M += x*x; break;
        }}
    M = (scelta == 2) ? M : M-1; //toglie l'1 dell'inizializzazione tranne se la media è geometrica perchè gli altri casi sono somme
    
    switch(scelta){     //calcola il risultato da stampare  
        case 1: M /= n; break;
        case 2: M = pow(M, 1./n); break;
        case 3: M = n/M; break;
        case 4: M = sqrt(M/n); break;
    }
    printf("\nLa media corrispondente a %d è = %lf ", scelta, M);
    return 0;
}