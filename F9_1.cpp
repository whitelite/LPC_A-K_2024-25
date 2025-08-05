/*Esercizio F9_1
	Scrivere un programma C++ strutturato in funzioni che acquisisce da tastiera un
	numero intero 0 < n ≤ 5, gli elementi di una matrice A ∈ Rn×n che sia a dominan-
	za diagonale stretta e le componenti di un vettore reale b ∈ Rn ; successivamente
	approssima la soluzione del sistema lineare Ax=b con il metodo di Jacobi, preven-
	tivando al massimo 100 iterazioni e utilizzando come criterio di arresto a posteriori
	il controllo che la norma infinito della differenza tra l’approssimazione corrente e
	l’approssimazione precedente sia all’arresto della procedura minore di 10−4 ; infine
	stampa sul video la “soluzione” e il numero di iterazioni compiute.
*/

#include <iostream>
#define N 5

typedef double mat[N][N];
typedef double vet[N];



double modd(double);						//OK

int diag_str(mat, int); 					//OK

int input_mat(mat);							//OK

void input_vet(vet, int);					//OK

double norma_inf(vet, int);					//OK

void copia_vet(vet, vet, int);				//OK

void iter_J(mat, vet, vet, vet, int);		//OK

int J_posteriori(mat, vet, vet, int);		//OK

void stampa_vet(vet, int);					//OK

int main(void){
	mat a; vet b, x = {0}; int n;

	do {n = input_mat(a); if (!diag_str(a, n)) printf("Non a dominanza diagonale stretta, reinserire la matrice.\n");}while(!(diag_str(a, n)));
	
	printf("Inserire le componenti del vettore b:\n");
	input_vet(b, n);
	int iter = J_posteriori(a, b, x, n);						
	printf("Soluzione con precisione 10^-4 dopo %d iterazioni:\n", iter);
	stampa_vet(x, n);
	return 0;

}









double modd(double n){
	return (n < 0) ? -n : n;
}

int diag_str(mat a, int n){
	double somma = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){                //sommo tutti gli elementi della riga in modulo (salto se è sulla diagonale o uno zero di macchina)
			if (!(i == j || a[i][j] == 0))                  
				somma += modd(a[i][j]);
			}
		if ( modd(a[i][i]) <= somma) return 0;            //controlla se è a dominanza diag stretta, se non lo è ritorna falso
		somma = 0;
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

double norma_inf(vet x, int n){					//calcola la norma infinito
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

int J_posteriori(mat a, vet b, vet xk, int n){
    vet err, xksup;                               
    int cont = 0;
    do{
        copia_vet(xk, xksup, n);                            	//ricopio il vettore dell'iterazione precedente nel supporto
        iter_J(a, b, xksup, xk, n);                            	//itero Jacobi
        for (int i = 0; i < n; i++)                         	//calcolo il vettore errore
            err[i] = xk[i] - xksup[i];
	}while(++cont < 100 && norma_inf(err, n) >= 1.e-4);         //controllo se norma_inf dell'errore è più piccola della tolleranza 
	return cont;                                            	//e continuo di conseguenza, restiruisco il contatore
}

void stampa_vet(vet b, int n){
	for (int i = 0; i < n; i++)
		printf("[%lf]\n", b[i]);
	return;
}