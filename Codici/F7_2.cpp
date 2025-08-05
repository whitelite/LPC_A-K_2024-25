/*Esercizio F7_2
	Scrivere un programma C++ strutturato in funzioni che costruisce la seguente
	matrice A come da consegna e ne calcola e stampa sul video la somma s e il prodotto p degli elementi diagonali, e i valori n1 e n 2 definiti come da consegna
*/

#include <cstdio>
#define N 5
typedef int matrice[N][N];   //creiamo il tipo della matrice




void crea_matrice(matrice);

int somma_diag(matrice);

int prod_diag(matrice);

int mod_max_somma_righe(matrice);

int mod_max_somma_colo(matrice);


int main(void){
	matrice a = {{0}};
	crea_matrice(a);//inizializza la matrice e calcola ogni valore richiesto...
	int s = somma_diag(a);
	int p = prod_diag(a);
	int n_1 = mod_max_somma_righe(a);
	int n_2 = mod_max_somma_colo(a);
	printf("\ns == %d\np == %d\nn_1 == %d\nn_2 == %d\n", s, p, n_1, n_2);  //... e lo stampa sul video

	return 0;
}






void crea_matrice(matrice a){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)      		//cicliamo ogni elemento della matrice
			switch (j-i){                  		//e gli assegniamo il corrispondente valore in base
			case  1:;						    //alla differenza tra indice di riga e colonna
			case -1: a[i][j] = -1; break;
			case 0: a[i][j] = 2; break;
			};
	return;
}

int somma_diag(matrice a){
	int somma = 0;                                  //uso un solo loop perchè so già che considero solo gli elementi
	for (int i = 0; i < N; i++)                     //con lo stesso indice riga e colonna
		somma += a[i][i];                   
	return somma;
}

int prod_diag(matrice a){
	int prodotto = 1;
	for (int i = 0; i < N; i++)                     //uguale a quello di sopra, ma inizializzo il prodotto come 1 perchè prodotto
		prodotto *= a[i][i];
	return prodotto;
}

int mod_max_somma_righe(matrice a){
	int somma = 0, nsomma = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)                     	//ciclo ogni elemento della matrice
			somma += (a[i][j] < 0) ? -a[i][j] : a[i][j];  	//calcolo la somma dei moduli di ogni riga
		if (somma > nsomma) nsomma = somma;			    	//confronto la somma con quella della riga precedente e la aggiorno se è maggiore
		somma = 0;}                                     	//resetto la somma e ricomincio, lo faccio per ogni riga
	return nsomma;
}

int mod_max_somma_colo(matrice a){
	int somma = 0, nsomma = 0;                        		//esattamente uguale a quello di sopra, mi è bastato scambiare l'indice riga con 
	for (int i = 0; i < N; i++){                      		//quello colonna, la logica rimane la stessa
		for (int j = 0; j < N; j++)
			somma += (a[j][i] < 0) ? -a[j][i] : a[j][i];
		if (somma > nsomma) nsomma = somma;
		somma = 0;}
	return nsomma;
}