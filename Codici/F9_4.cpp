/*Esercizio F9_4
    Scrivere un programma C++ analogo al precedente, con la differenza che viene uti-
    lizzato il criterio di arresto a priori analizzato a lezione per garantire la precisione
    τ della soluzione approssimata. Confrontare con il numero di iterazioni restituito
    - a parità di n e τ - dal programma al punto precedente.
*/

#include <cmath>        //log
#include <cstdio>
#define N 100           

typedef int mat[N][N];
typedef double vet[N];



int modi(int);                                  //OK

double modd(double);                            //OK

void iter_J(mat, vet, vet, vet, int);           //OK

double norma_inf(vet, int);                     //OK

double calc_lam(mat, int);                      //OK

void copia_vet(vet, vet, int);                  //OK

void J_priori(mat, vet, vet, int, int);         //OK

int calc_iter_J(mat, vet, vet, double, int);    //OK

void crea_A(mat, int);                          //OK

void crea_b(mat, vet, int);                     //OK

void stampa_vet(vet, int);                      //OK


int main(void){
    mat a = {{0}}; vet b = {0}, x = {0}; double tau; int n;

    printf("Inserire un numero intero n (5 <= n <= 100): ");
    do{scanf("%d", &n); if (n < 5 || n > 100) printf("Reinserire.\n");}while(n < 5 || n > 100);
    printf("Inserire la tolleranza tau ( 0 < tau <= 10^-4): ");
    do{scanf("%lf", &tau); if (tau > 1.e-4 || tau <= 0) printf("Reinserire.\n");}while(tau > 1.e-4 || tau <= 0);
    crea_A(a, n);
    crea_b(a, b, n);
    int iter = calc_iter_J(a, b, x, tau, n);
    J_priori(a, b, x, iter, n);
    printf("Soluzione approssimata con tau = %e dopo %d iterazioni:\n", tau, iter);
    stampa_vet(x, n);
    return 0;

}











int modi(int n){
    return (n < 0) ? -n : n;
}

double modd(double n){
    return (n < 0) ? -n : n;
}

void iter_J(mat a, vet b, vet x, vet xi, int n){    								
    for (int i = 0; i < n; i++){                                            
        xi[i] = 0;                                                                //resetta l'entrata
		for (int j = 0; j < n; j++){
            if (!(i == j || a[i][j] == 0))                   					  
            	xi[i] -= x[j] * a[i][j];}                                         //sottraggo i prodotti tra le componenti è i corrispondenti coefficienti
		xi[i] += b[i];							              			 		  //saltando 1'iterazione se i == j (nella moltiplicazione rc tra C e x(k-1) sarebbe moltiplicato per 0)
        xi[i] /= a[i][i];                           			 				  //sommo il corrispondente termine noto
    }                                                                             //divido tutto per il coefficiente corrispondente sulla diagonale
    return;
}

double norma_inf(vet x, int n){
    double norma, onorma = 0;
    for (int i = 0; i < n; i++){
        norma = modd(x[i]);
        if (norma > onorma) onorma = norma;
    }
    return onorma;
}   

double calc_lam(mat a, int n){                              //calcola la costante di contrattività
    double lambda, lambda_old = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!(i == j || a[i][j] == 0))                            //salta l'iterazione se deve sommare l'elemento sulla diagonale o se il coefficiente è nullo
                lambda += a[i][j];
        }                                                                   //non uso il modulo perchè sono tutte positive le entrate della matrice
        lambda /= a[i][i];
        if ( lambda > lambda_old) lambda_old = lambda;
    }
    return lambda_old;
}

void copia_vet(vet a, vet b, int n){
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    return;
}

void J_priori(mat a, vet b, vet xk, int iter, int n){        //passo il numero di iterazioni calcolato con calc_iter_J
    vet xksup;
    for (int k = 1; k < iter; k++){                                     //eseguo le iterazioni di jacobi ed esco 
        copia_vet(xk, xksup, n);                                        //parto da 1 siccome la prima già l'ho eseguita nel calcolo del numero di iterazioni
        iter_J(a, b, xksup, xk, n);
    }
    return;
}

int calc_iter_J(mat a, vet b, vet xk, double tau, int n){       //come nell'esercizio F9_2
    vet err, xksup; double lambda = calc_lam(a, n);
    copia_vet(xk, xksup, n);
    iter_J(a, b, xksup, xk, n);
    for (int i = 0; i < n; i++)
        err[i] = xksup[i] - xk[i];
    return log2((1-lambda) * tau / norma_inf(err, n)) / log2(lambda) + 1 ;         
}

void crea_A(mat a, int n){
    for ( int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            switch(modi(i-j)){
                case 0: a[i][j] = 12; break;
                case 2: a[i][j] = 1; break;
            }
    return;
}

void crea_b(mat a, vet b, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i] += a[i][j];
    return;
}

void stampa_vet(vet b, int n){
    for (int i = 0; i < n; i++)
        printf("[%.13lf]\n", b[i]);
    return;
}