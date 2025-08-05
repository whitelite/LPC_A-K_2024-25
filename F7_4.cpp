/*Esercizio F7_4
    Scrivere un programma C++ strutturato in funzioni che acquisisce da tastiera
    un numero intero positivo n ≤ 50, costruisce una matrice triangolare inferiore L
    di n righe ed n colonne ad elementi interi random tra 1 e 15 e un vettore b di
    dimensione n contenente elemento per elemento la somma delle componenti della
    corrispondente riga di L; successivamente risolve il sistema lineare Lx=b e stampa
    sul video la somma delle componenti del vettore x (che dovrebbe essere uguale a
    n, dato che le componenti di x dovrebbero essere tutte uguali a 1).

*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#define N 50

typedef int mat[N][N];
typedef int vet[N];         //uso sia matrici che vettori di interi dato che i valori con cui sto lavorando non dovrebbero dare problemi nelle operazioni
                            //nel forward sto togliendo tutti gli elementi che avevo sommato meno che l'i-esimo, per il quale divido il risultato delle sottrazioni


int mat_triang(mat);

void crea_b (mat, vet, int);

void forward(mat, vet, vet, int);

int main(void){
    mat l = {{0}}; vet b = {0}, x = {0}; int s = 0;

    int n = mat_triang(l);
    crea_b(l, b, n);
    forward(l, b, x, n);

    for(int i = 0; i < n; i++) s += x[i];
    printf("Somma delle componenti del vettore soluzione x: %d\n", s);

    return 0;
}




int mat_triang(mat l){
    int n;
    printf("Inserire la taglia della matrice quadrata L (massimo %d): ", N);
    do{scanf("%d", &n); if( n > N || n <= 0) printf("Reinserire: ");}while(n > N || n <= 0);
    srand(time(0));                         //inizializzo il generatore
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)        //inizio dall'elemento sulla diagonale siccome deve essere triangolare
            l[i][j] = rand()%15+1;          //facendo il modulo mi assicuro valori tra 0 e 14, aggiungendo 1 tra 1 e 15
    return n;
}


void crea_b (mat a, vet b, int n){          //crea il vettore che come componenti ha la somma della riga di indice corrispondente della matrice A
    for (int i = 0; i < n; i++)     
        for (int j = 0; j < n; j++)
            b[i] += a[i][j];
    return;
}

void forward(mat a, vet b, vet x, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++)         //nella prima iterazione salta il secondo loop for perchè i = j subito
            x[i] -= x[j]*a[i][j];           //somma l'opposto di tutti i prodotti tra soluzioni trovate e corrispondenti coefficienti
        x[i] += b[i]; x[i] /= a[i][i];      //somma il corrispondente termine noto e divide tutto per il coefficiente diagonale corrispondente
    }
    return;
}