/* Esercizio F2_1

    Programma che acquisisce da tastiera un numero intero positivo n
    (se non è positivo il programma termina con un messaggio opportuno)
    e i reali positivi x_1:x_n (anche qui controlla che siano tutti positivi)
    e stampa media aritmetica, geometrica, armonica e quadratica

*/

#include <cstdio>
#include <cmath>

int main(void){

   int n; double x, Ma=0, Mg=1, Mh=0, Mq=0;
    printf("Inserire il numero positivo n = ");
    scanf("%d", &n);
    if (n <= 0)
        {printf("\nn non è un intero positivo.\n");
        return 1;}
    for (int i = 1; i <= n; i++)
        {printf("\nInserire x_%d --> ", i);
         scanf("%lf", &x);
         if ( x< 1.e-8) //sarebbe la precisione di macchina
             {printf("\nx_%d non è un reale positivo. \n", i);
             return 1;}
         Ma += x; Mg *= x; Mh += 1/x; Mq += x*x;}
    printf("\nMedie (in ordine non decrescente):\n");
    printf("\nMh = %lf\n\nMg = %lf\n",n/Mh , pow(Mg, 1./n));
    printf("\nMa = %lf\n\nMq = %lf\n", Ma/n , sqrt (Mq/n));
    return 0;
}
