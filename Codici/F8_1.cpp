/*Esercizio F8_1
    Scrivere un programma C++ strutturato in funzioni cherisolve il sistema lineare By=c con il metodo di eliminazione di Gauss senza rior-
    dinamento pivotale e stampa sul video il vettore y (che dovrebbe avere tutte
    componenti uguali a 1).
*/

#include <cstdio>
#define N 5
typedef double mat[N][N];
typedef double vet[N];



int moduli(int);

void crea_B (mat);

void riduzione_Gauss (mat, vet, int);

void backward (mat, vet, vet, int);

void stampa_vet(vet, int);

int main(void){
    mat b = {{0}}; vet c = {2, 1, 1, 1, 2}, y = {0};
    crea_B(b);
    riduzione_Gauss(b, c, N);
    backward(b, c, y, N);
    printf("Vettore y:\n");
    stampa_vet(y, N);
    return 0;
}






int moduli(int n){
    return (n < 0) ? -n : n;
}

void crea_B (mat b){
    for (int i = 0; i < N; i++)
        for (int j = i-1; j <= i+1; j++)
            if ( !(j == -1 || j == N))        //controllo il valore dell'indice di colonna per evitare buffer overflow
                switch ((i-j)){
                    case -1: ;
                    case 1: b[i][j] = -1; break;
                    case 0: b[i][j] = 3; break;        
                }
    return;
}

void riduzione_Gauss (mat a, vet b, int n){
    double m;
    for (int r = 0; r < n-1; r++)
        for (int i = r+1; i < n; i++){          //non azzero gli elementi del tipo a[i][i-1] perchè nel backward non li uso
            m = a[i][r]/a[r][r];                //sarebbero operazioni inutili 
            for (int j = r+1; j < n; j++)
                a[i][j] -= m * a[r][j];
            b[i] -= m*b[r];
            }
    return;
}

void backward (mat a, vet b, vet x, int n){
    for (int i = n-1; i > -1; i--){              //praticamente come il forward dell'esercizio precedente ma 
        for (int j = i+1; j < n; j++)            //modificando partenza degli indici di riga e colonna
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