/*Esercizio F3_2
    Scrivere un programma C++ che acquisisce da tastiera due numeri interi n e k,
    controlla che valga 0 ≤ k ≤ n (altrimenti ne permette nuovamente l’inserimento
    per altre 5 volte al massimo) e se il controllo è andato a buon fine stampa sul video
    il coefficiente binomiale.
*/

#include <cstdio>


int main(void){

    int n,k, i=0; double bin = 1;    //il binomiale lo tengo in doppia precisione dato che potrebbe essere molto grande
    // loop per i tentativi di inserimento dei dati
    do{
        if(i == 6) {printf("\nLimite di inserimenti superato"); return 1;}  //è il primo in ordine di esecuzione perchè alla 6^ iterazione è il primo che deve essere eseguito ed è sempre falso negli altri casi
        if(k > n || k < 0) printf("\nI due numeri non rispettano i vincoli del binomiale, reinserirli (hai ancora %d tentativi)", 6-i); //con k=0 e n=0 è falso, quindi non tocca mai la prima iterazione
        printf("\nInserire il primo termine del binomiale: ");
        scanf("%d", &n);
        printf("\nInserire il secondo termine del binomiale: ");
        scanf("%d", &k);
        if(!(k > n || k < 0)) break;    //se vanno bene i dati esce, altrimenti incrementa i e continua
    }
    while(++i <= 6);
    if (k == 0 || k == n) {printf("\nIl binomiale %d su %d è: %.0f", n, k, bin); return 0;} //se k=0 o k=n allora stampa 1 ed esce... 
    for (int j = 1; j <= n-k; j++) bin *= (k+j)/j;      //...altrimenti calcola il binomiale secondo la formula fornita
    printf("\nIl binomiale %d su %d è: %.0f", n, k, bin); return 0;
}