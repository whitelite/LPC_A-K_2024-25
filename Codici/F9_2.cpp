/*Esercizio F9_2
    Scrivere un programma C++ analogo al precedente, con la differenza che viene
    utilizzato il criterio di arresto a priori analizzato a lezione per garantire che la
    norma infinito dell’errore commesso all’arresto della procedura sia minore di 10−4
*/

#include <cstdio>
#include <cmath>    //log

#define N 5
#define TAU 1.e-4


typedef double mat[N][N];
typedef double vet[N];





double modd(double);                                        //OK

int diag_strd_lam(mat, double&, int);                       //OK

int input_mat(mat);                                         //OK

void input_vet(vet, int);                                   //OK

double norma_inf(vet, int);                                 //OK

void copia_vet(vet, vet, int);                              //OK

void iter_J(mat, vet, vet, vet, int);                       //OK

void stampa_vet(vet, int);                                  //OK

void J_priori(mat, vet, vet, int, int);                     //OK

int calc_iter_J(mat, vet, vet, double, double, int);        //OK


int main(void){
    mat a; vet b, x = {0}; int n, controllo; double lambda;

    do {
        n = input_mat(a); 
        controllo = diag_strd_lam(a, lambda, n); 
        if (!controllo) 
        printf("Non a dominanza diagonale stretta, reinserire la matrice.\n");}
    while(!controllo);
	
	printf("Inserire le componenti del vettore b:\n");
	input_vet(b, n);
	int iter = calc_iter_J(a, b, x, TAU, lambda, n);
    J_priori(a, b, x, iter, n);
	printf("Soluzione con precisione 10^-4 dopo %d iterazioni:\n", iter); 
	stampa_vet(x, n);
	return 0;
}


double modd(double n){
	return (n < 0) ? -n : n;
}

int diag_strd_lam(mat a, double& lam, int n){               //dato che già faccio tutti i calcoli per controllare che la matrice sia a diagonale strettamente dominante, ho pensato che effettivamente costa meno calcolarsi subito lambda
	lam = 0; double lamsup = 0, mod_ii;                     //invece di rifare tutti i calcoli dopo
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)                                 //sommo tutti gli elementi della riga in modulo (salto se è sulla diagonale)
			if (!(i == j || a[i][j] == 0))                 
			    lamsup += modd(a[i][j]);
        mod_ii = modd(a[i][i]);
		if ( mod_ii <= lamsup) return 0;            //controlla se è a dominanza diag stretta, se non lo è ritorna falso
		lamsup /= mod_ii;                           //procede a calcolare lambda 
        if (lamsup > lam) lam = lamsup;    
        lamsup = 0;
	}   
	return 1;                                       //altrimenti restituisce vero
}

int input_mat(mat a){
	int n;
	printf("Inserire la taglia della matrice quadrata A a dominanza diagonale stretta(massimo %d): ", N);
	do{scanf("%d", &n); if (n > N || n <= 0) printf("Reinserire.\n");}while(n > N || n <= 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			printf("A[%d][%d]= ", i+1, j+1);
			scanf("%lf", &a[i][j]);
		}
	return n;
}

void input_vet(vet b, int n){
	for (int i = 0; i < n; i++){
		printf("b[%d]= ", i+1);
		scanf("%lf", &b[i]);
	}
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

void copia_vet(vet a, vet b, int n){
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    return;
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

void stampa_vet(vet b, int n){
	for (int i = 0; i < n; i++)
		printf("[%lf]\n", b[i]);
	return;
}


void J_priori(mat a, vet b, vet xk, int iter, int n){       //passo il numero di iterazioni calcolato con calc_iter_J
    vet xksup;
    for (int k = 1; k < iter; k++){                                     //eseguo le iterazioni di jacobi ed esco
        copia_vet(xk, xksup, n);                                        //parto da 1 (saltando 1 iterazione) perchè già l'ho eseguita nel calcolo del numero di iterazioni
        iter_J(a, b, xksup, xk, n);
    }
    return;
}

int calc_iter_J(mat a, vet b, vet xk, double tau, double lambda, int n){
    vet err, xksup;                                                                //calcola la costante di contrattività associata alla matrice
    copia_vet(xk, xksup, n);
    iter_J(a, b, xksup, xk, n);                                             //itera una volta Jacobi, calcola il vettore errore e la norma associata
    for (int i = 0; i < n; i++)
        err[i] = xksup[i] - xk[i];
    return log((1-lambda) * tau / norma_inf(err, n)) / log(lambda) + 1;     //restituisce la parte intera del criterio
}