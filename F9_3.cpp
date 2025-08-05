/*Esercizio F9_3
    Scrivere un programma C++ strutturato in funzioni che acquisisce da tastiera
    un numero intero 5 ≤ n ≤ 100 e un numero reale 0 < τ ≤ 10−4 ; costruisce la
    matrice A di dimensioni n × n contenente tutti elementi nulli ad esclusione degli
    elementi diagonali, che sono tutti uguali a 12, e degli elementi per i quali indice
    di riga e colonna hanno differenza in modulo uguale a 2, che sono tutti uguali a 1;
    costruisce il vettore b contenente ordinatamente la somma delle righe di A; calcola
    con il metodo di Jacobi una soluzione approssimata del sistema lineare Ax=b
    utilizzando il criterio di arresto a posteriori analizzato a lezione per garantirne
    la precisione τ ; infine stampa la soluzione approssimata ottenuta e il numero di
    iterazioni che sono state compiute.
*/

#include <cstdio>
#define N 100         

typedef int mat[N][N];
typedef double vet[N];



int modi(int);                                          //OK

double modd(double);                                    //OK

void iter_J(mat, vet, vet, vet, int);                   //OK

double norma_inf(vet, int);                             //OK

double calc_lam(mat, int);                              //OK

void copia_vet(vet, vet, int);                          //OK

int J_posteriori(mat, vet, vet, double, int);           //OK

void crea_A(mat, int);                                  //OK

void crea_b(mat, vet, int);                             //OK

void stampa_vet(vet, int);                              //OK

int main(void){
    mat a = {{0}}; vet b = {0}, x = {0}; double tau; int n;

    printf("Inserire un numero intero n (5 <= n <= 100): ");
    do{scanf("%d", &n); if (n < 5 || n > 100) printf("Reinserire.\n");}while(n < 5 || n > 100);
    printf("Inserire la tolleranza tau ( 0 < tau <= 10^-4): ");
    do{scanf("%lf", &tau); if (tau > 1.e-4 || tau <= 0) printf("Reinserire.\n");}while(tau > 1.e-4 || tau <= 0);
    crea_A(a, n);
    crea_b(a, b, n);
    int iter = J_posteriori(a, b, x, tau, n);
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
            if (i != j && a[i][j] != 0)                       //salta l'iterazione se deve sommare l'elemento sulla diagonale o se il coefficiente è nullo
                lambda += a[i][j];  
        }                                                     //non metto il modulo che le entrate della matrice sono tutte positive
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

int J_posteriori(mat a, vet b, vet xk, double tau, int n){
    vet err, xksup; double lambda = calc_lam(a, n);                     //calcolo lambda
    lambda = lambda/(1-lambda);                                         //calcolo lambda/(1-lambda)
    tau /= lambda;                                                      //divido tau per lambda così da farmi una sola operazione al posto di moltiplicare sempre la norma_inf per lambda
    int cont = 0;
    do{
        cont++;
        copia_vet(xk, xksup, n);                            //ricopio il vettore dell'iterazione precedente nel supporto
        iter_J(a, b, xksup, xk, n);                         //itero Jacobi
        for (int i = 0; i < n; i++)                         //calcolo il vettore "errore"
            err[i] = xksup[i] - xk[i];
    }while(norma_inf(err, n) >= tau);                       //controllo se norma_inf dell'"errore" è più piccola della tolleranza modificata 
    return cont;                                            //e continuo di conseguenza, restituisco il contatore
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
        printf("[%.15lf]\n", b[i]);
    return;
}