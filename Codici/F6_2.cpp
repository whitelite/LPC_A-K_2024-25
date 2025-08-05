/*Esercizio F6_2
    Scrivere un programma C++ che acquisisce da tastiera un numero intero positivo
    n ≤ 10 e le componenti di un vettore reale v di dimensione n; successivamente
    riordina le componenti di v in senso crescente con l’algoritmo selection sort e le
    stampa sul video; infine calcola la mediana delle componenti di v e la stampa
    sul video. Usare le funzioni lettura_dimensione, lettura_vettore, stampa_vettore,
    ordinamento, scambia.

*/
#include <cstdio>
#define N 10        //dimensione massima



int lettura_dimensione();

void lettura_vettore(double[], int);

void scambia(double[], int, int);

void ordinamento(double[], int);

void stampa_vettore(double[], int);

int main(void){
    double v[N];
    int n = lettura_dimensione();
    lettura_vettore(v, n);
    ordinamento(v, n);
    printf("\nIl vettore riordinato:\n");
    stampa_vettore(v, n);
    printf("\nMediana delle componenti --> %lf\n", v[n/2]);       //la mediana è facilemente calcolabile grazie alla divisione tra interi
    return 0;
}

int lettura_dimensione(){
    int n;
    printf("Inserire la dimensione del vettore (massimo 10):");
    scanf("%d", &n);
    return n;
}

void lettura_vettore(double v[], int n){
    printf("Inserire le componenti del vettore:\n");
    for(int i = 0; i < n; i++){
        printf("v[%d] : ", i+1);
        scanf("%lf", &v[i]);
    }
    return;
}

void scambia(double v[], int x, int y){
    double temp;
    temp = v[x];
    v[x] = v[y];
    v[y] = temp;
    return;
}

void ordinamento(double v[], int n){        //algoritmo selection sort visto a lezione
    int indmin;
    for (int i = 0; i <n-1; i++){
        indmin = i;
        for (int j = i+1; j< n; j++)
            if(v[j] < v[indmin]) indmin = j;
        if (indmin != i) scambia(v, i, indmin);
    }
    return;
}


void stampa_vettore(double v[], int n){
    for (int i = 0; i<n; i++)
        printf("[%lf]\n", v[i]);
    return;
}