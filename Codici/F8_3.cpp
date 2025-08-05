/*Esercizio F8_3
    Scrivere un programma C++ strutturato in funzioni che calcola il prodotto C =
    AB, dove A è come da consegna e B è la matrice costruita nell'esercizio 1, 
    e stampa sul video det(A), det(B) e det(C)
*/

#include <cstdio>
#define N 5
typedef double mat[N][N];



double moduld(double);

int moduli(int);

void crea_B (mat);

void crea_A(mat);

void prodotto_rc(mat, mat, mat, int);

void copia_mat(mat, mat, int);

int mod_pivot(mat, int, int);

void scambia_r(mat, int, int, int);

double det(mat, int);

int main(void){
    mat a = {{0}}, b = {{0}}, c = {{0}};
    crea_A(a); crea_B(b);
    prodotto_rc(a, b, c, N);
    printf("Determinante di A: %lf\nDeterminante di B: %lf\nDeterminante di C: %lf\n", det(a, N), det(b, N), det(c, N));
    return 0;
}



double moduld(double n){
    return (n < 0) ? -n : n;
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

void crea_A(mat a){
    for (int i = 0; i < N; i++)
        for (int j = i; j <= i+1  ; j++)
            if (!(j == N))                //controlla l'indice colonna per evitare buffer overflow
                switch (i-j){
                    case 1: a[i][j] = 0.5; break;
                    case 0: a[i][j] = -1; break;         
                }
    return;
}

void prodotto_rc(mat a, mat b, mat c, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    return;
}

void copia_mat(mat a, mat b, int n){                    //copia la matrice elemento per elemento
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = a[i][j];
    return;
}

int mod_pivot(mat a, int k, int n){
    int pivot = k; double mod,                          //inizializza old_mod e pivot rispettivamente al modulo di a[k][k] e k
    old_mod = moduld(a[k][k]);           
    for (int i = k+1; i<n; i++){
        mod = moduld(a[i][k]);                           //calcola il modulo dell'elemento i-esimo della colonna k-esima di a
        if (mod > old_mod) {                            //lo confronta con il più grande trovato fino a quel momento
            old_mod = mod;                              //se il nuovo è più grande, aggiorna le variabili di conseguenza
            pivot = i;
        }
    }
    return pivot;                                       //restituisce il pivot trovato
}

void scambia_r(mat a, int k, int kn, int n){    
    double temp;                                            //scambia gli elementi della riga k-esima a partire dal k-esimo
    for (int i = k; i < n; i++){                            //perchè quelli precedenti non li considero in quanto uguali a 0
        temp = a[k][i];                                     //anche se effettivamente non li pongo come tali
        a[k][i] = a[kn][i];                                 //ma semplicemente li trascuro nella risoluzione del sistema
        a[kn][i] = temp;
    }
    return;
}


double det(mat d, int n){  
    double m, deter = 1; int sgn = 1, pivot; mat a;
    copia_mat(d, a, n);                             //copia la matrice d di cui voglio calcolare il determinante
    for (int r = 0; r < n-1; r++){                  //nella matrice a, la riduce a scala tramite Gauss con riordinamento
        pivot = mod_pivot(a, r, n);                 //pivotale, tenendo conto dello scambio di righe in sgn
        if (pivot > r){
            scambia_r(a, r, pivot, n);
            sgn *= -1;}
        for (int i = r+1; i < n; i++){                
            m = a[i][r]/a[r][r];                       
            for (int j = r+1; j < n; j++)
                a[i][j] -= m * a[r][j];
            }
    }
    for (int i = 0; i < n; i++) deter *= a[i][i];       //moltiplico tra di loro gli elementi diagonali
    return sgn*deter;                                   //restituisco il determinante per il segno
}