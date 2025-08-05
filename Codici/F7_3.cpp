/*Esercizio F7_3
  Scrivere un programma C++ strutturato in funzioni che calcola il prodotto righe
  per colonne C = AB, dove A è la matrice definita nell’esercizio precedente e B è
  data dall'esercizio e stampa a sul video la matrice C
*/


#include <cstdio>
#define N 5
typedef int matrice[N][N];		//tutte le operazioni che faccio sono chiuse negli interi (moltiplicazioni e somme)
								//mi basta quindi int 


void crea_A(matrice);

void crea_B(matrice);

void prodotto_rc(matrice, matrice, matrice);

void stampa_mat(matrice);

int main(void){
	matrice a = {{0}},b = {{0}},c = {{0}};

	crea_A(a); crea_B(b);

	prodotto_rc(a, b, c);

	stampa_mat(c);

	return 0;
  
}


void crea_A(matrice a){
  for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)    		  //cicliamo ogni elemento della matrice
	  switch (j-i){                		  //e gli assegniamo il corrispondente valore in base
	  case 1: ;   						  //alla differenza tra indice di riga e colonna
	  case -1: a[i][j] = -1; break;
	  case 0: a[i][j] = 2; break;
	  };
  return;
}

void crea_B(matrice a){
   for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)    		  //cicliamo ogni elemento della matrice
	  switch (j-i){               	      //e gli assegniamo il corrispondente valore in base
	  case 1: ;						      //alla differenza tra indice di riga e colonna
	  case -1: a[i][j] = 1; break;
	  };
  return;
}

void prodotto_rc(matrice a, matrice b, matrice c){
	for (int i = 0; i < N; i++)                                 
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
		  		c[i][j] += a[i][k]*b[k][j];
  return;
}


void stampa_mat(matrice a){
	for (int i = 0; i < N; i++){
		printf("\n[%d ", a[i][0]);
		for (int j = 1; j < N; j++)
			printf("%d ", a[i][j]);
		printf("]");}
	
	printf("\n");
	return;
}