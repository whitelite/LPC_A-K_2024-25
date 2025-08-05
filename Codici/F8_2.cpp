/*Esercizio F8_2
    Scrivere un programma C++ strutturato in funzioni che acquisisce da tastiera un
    numero intero n tale che 0 < n ≤ 50, genera in modo casuale la matrice A ∈ Rn×n
    con elementi appartenenti all’intervallo dell’asse reale [−1, 1], costruisce il vettore b
    contenente elemento per elemento la somma delle componenti della corrispondente
    riga di A, risolve il sistema lineare Ax=b con il metodo di eliminazione di Gauss
    con riordinamento pivotale, e stampa sul video le componenti del vettore soluzione
    x (che dovrebbe avere tutte componenti uguali a 1).
    
*/


#include <cstdio>
#include <ctime>
#include <cstdlib>
#define N 50
typedef double mat[N][N];
typedef double vet[N];



double modul(double n);

int mat_rand (mat);

void crea_b (mat, vet, int);

int mod_pivot(mat, int, int);

void scambia_r (mat, vet, int, int, int);

void riduzione_Gauss_pivot (mat, vet, int);

void backward (mat, vet, vet, int);

void stampa_vet(vet, int);


int main(void){
    mat a = {{0}}; vet x = {0}, b = {0};
    
    int n = mat_rand(a);

    crea_b (a, b, n);

    riduzione_Gauss_pivot(a, b, n); backward(a, b, x, n);
    printf("Vettore x:\n");
    stampa_vet(x, n);
    
    return 0;

}








double modul(double n){
    return (n < 0)? -n : n;
}

int mat_rand (mat m){  
    int n;
    printf("Inserire la taglia della matrice quadrata A (massimo %d): ", N);
    do{scanf("%d", &n); if(n>N || n <= 0) printf("Reinserire.\n");}while(n>N || n <= 0);
    srand(time(0));                     //inizializzo il generatore
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            m[i][j] = (2*double(rand())/RAND_MAX) - 1;
        }
    return n;
}

void crea_b (mat a, vet b, int n){  
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i] += a[i][j];
    return;
}

int mod_pivot(mat a, int k, int n){
    int pivot = k; double mod,                          //inizializza old_mod e pivot rispettivamente al modulo di a[k][k] e k
    old_mod = modul(a[k][k]);           
    for (int i = k+1; i<n; i++){
        mod = modul(a[i][k]);                           //calcola il modulo dell'elemento i-esimo della colonna k-esima di a
        if (mod > old_mod) {                            //lo confronta con il più grande trovato fino a quel momento
            old_mod = mod;                              //se il nuovo è più grande, aggiorna le variabili di conseguenza
            pivot = i;
        }
    }
    return pivot;                                       //restituisce il pivot trovato
}

void scambia_r (mat a, vet b, int k, int kn, int n){    
    double temp;                                            //scambia gli elementi della riga k-esima a partire dal k-esimo
    for (int i = k; i < n; i++){                            //perchè quelli precedenti non li considero in quanto uguali a 0
        temp = a[k][i];                                     //anche se effettivamente non li pongo come tali
        a[k][i] = a[kn][i];                                 //ma semplicemente li trascuro nella risoluzione del sistema
        a[kn][i] = temp;
    }
    temp = b[k];
    b[k] = b[kn];
    b[kn] = temp;
    return;
}


void riduzione_Gauss_pivot (mat a, vet b, int n){  
    double m;
    int pivot;
    for (int r = 0; r < n-1; r++){
        pivot = mod_pivot(a, r, n);                     //cerca il pivot
        if (pivot > r)                          
            scambia_r(a, b, r, pivot, n);               //scambia le righe
        for (int i = r+1; i < n; i++){                  //non azzero gli elementi del tipo a[i][i-1] perchè nel backward non li uso
            m = a[i][r]/a[r][r];                        //sarebbero operazioni inutili 
            for (int j = r+1; j < n; j++)               //itera
                a[i][j] -= m * a[r][j];
            b[i] -= m*b[r];
            }
        }
    return;
}

void backward (mat a, vet b, vet x, int n){
    for (int i = n-1; i >= 0; i--){                 //uguale all'esercizio precedente 
        for (int j = i+1; j < n; j++)              
            x[i] -= x[j] * a[i][j];
        x[i] += b[i]; x[i] /= a[i][i];
    }
    return;
}

void stampa_vet(vet v, int n){
    for (int i = 0; i<n; i++)
        printf("[%lf]\n", v[i]);
    return;
}