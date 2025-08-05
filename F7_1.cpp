/*Esercizio F7_1
    Scrivere un programma C++ strutturato in funzioni che acquisisce da tastiera un
    numero intero positivo n ≤ 5, gli elementi di una matrice A = (ai,j ) ∈ Rn×n - che
    dovranno essere introdotti per righe (prima gli elementi della prima riga, poi quelli
    della seconda, ecc.) - e le componenti di un vettore u = (uj ) ∈ Rn ; successivamente
    calcola e stampa sul video il vettore v = (vj ) ∈ Rn tale che v = Au, il vettore
    w = (wj ) ∈ Rn contenente elemento per elemento la somma delle componenti della
    P
    corrispondente colonna di A, ovvero wj = ni=1 ai,j .
    
*/

#include <cstdio>
#define N 5         //dimensione massima



int lettura_mat (double[][N]);

void lettura_vet(double[], int);

void prodotto_mat_vet (double[][N], double[], double[], int);

void somma_colonne (double[][N], double[], int);

void stampa_vet(double[], int);

int main(void){
    double a[N][N], u[N], v[N] = {0}, w[N] = {0};

    int n = lettura_mat(a);

    lettura_vet(u, n);
    
    prodotto_mat_vet(a, u, v, n);
    printf("Risultato prodotto matrice*vettore:\n");
    stampa_vet(v, n);
    printf("Vettore somma colonne della matrice:\n");
    somma_colonne(a, w, n);
    stampa_vet(w, n);
    return 0;
}







int lettura_mat (double mat[][N]){          //chiede la taglia della matrice e gli elementi. Restituisce la taglia
    int n;
    printf("Inserire la taglia della matrice quadrata A (massimo %d):", N);
    do{scanf("%d", &n);}while(n > N || n <= 0);
    printf("Inserire gli elementi della matrice\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%lf", &mat[i][j]);
    }
    return n;
}

void lettura_vet(double v[], int n){                    //chiede il vettore di dimensione uguale alla taglia della matrice
    printf("Inserire le componenti del vettore u:\n");
    for(int i = 0; i < n; i++){
        printf("u[%d]: ", i+1);
        scanf("%lf", &v[i]);
    }
    return;
}

void prodotto_mat_vet (double mat[][N], double op[], double res[], int n){      //prodotto matrice vettore
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i] += mat[i][j] * op[j];
    return;
}

void somma_colonne (double mat[][N], double res[], int n){          //somma colonna per colonna gli elementi e restituisce il vettore le cui entrate sono queste somme
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i] += mat[j][i];
    return;
}

void stampa_vet(double v[], int n){
    for (int i = 0; i<n; i++)
        printf("[%lf]\n", v[i]);
    return;
}