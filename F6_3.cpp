/*Esercizio F6_3
    Scrivere un programma C++ che acquisisce da tastiera un numero intero positivo
    n ≤ 10 e le componenti di un vettore reale v di lunghezza n; calcola e stampa sul
    video il prodotto e la media delle componenti del vettore v; successivamente scam-
    bia tra di loro la componente del vettore v che ha il minimo valore assoluto e la
    componente del vettore v che ha il massimo valore assoluto, dopo averne stampato
    gli indici sul video; infine stampa sul video il vettore ottenuto. Strutturare il pro-
    gramma in funzioni (lettura_dimensione, lettura_vettore, prodotto_vettore, me-
    dia_vettore, vettore_modulo, indice_minimo, indice_massimo, scambia_vettore,
    stampa_vettore).
*/
#include <cstdio>
#define N 10        //dimensione massima

int lettura_dimensione();

void lettura_vettore(double[], int);

double prodotto_vettore(double[], int);

double media_vettore(double[], int);

void vettore_modulo(double[], double[], int);

int indice_minimo(double[], int);

int indice_massimo(double[], int);

void scambia_vettore(double[], int, int);

void stampa_vettore(double[], int );

int main(void){
    double v[N], mod[N];

    int n = lettura_dimensione();
    lettura_vettore(v, n);
    printf("\nProdotto delle componenti --> %lf\nMedia delle componenti --> %lf\n", prodotto_vettore(v, n), media_vettore(v, n));
    
    vettore_modulo(v, mod, n);
    
    int indmax = indice_massimo(mod, n);
    int indmin = indice_minimo(mod, n);
    
    printf("\nIndice che corrisponde alla componente col massimo valore assoluto --> %d\nIndice che corrisponde alla componente col minimo valore assoluto --> %d\n", indmax+1, indmin+1);
    
    scambia_vettore(v, indmin, indmax);
    printf("\nVettore con indmax e indmin scambiati:\n");
    stampa_vettore(v, n);
    
    return 0;


}







int lettura_dimensione(){
    int n;
    printf("Inserire la dimensione del vettore (massimo 10):");
    scanf("%d", &n);
    return n;
}

void lettura_vettore(double v[], int n){
    printf("Inserire le componenti del vettore:\n");
    for(int i = 0; i < n; i++){
        printf("v[%d] : ", i+1);
        scanf("%lf", &v[i]);
    }
    return;
}

double prodotto_vettore(double v[], int n){
    double prod = 1;
    while (n) prod *= v[--n];
    return prod;
}

double media_vettore(double v[], int n){        //ho usato un ciclo while, si poteva fare benissimo anche con un ciclo for 
    double media = 0, inv = 1./n;
    while (n) media += v[--n];
    return media*inv;
}

void vettore_modulo(double v[], double mod[], int n){
    for (int i = 0; i<n; i++)
        mod[i] = (v[i] < 0) ? -v[i] : v[i];
    return;
}

int indice_minimo(double v[], int n){           //inizializza l'indice a 0 e lo compara con gli altri indici 
    int indmin = 0;     
    for (int i = 1; i<n; i++)
        if (v[i] < v[indmin]) indmin = i;       //aggiorna il valore se trova un indice la cui entrata è minore 
    return indmin;
}

int indice_massimo(double v[], int n){          //stessa logica della funzione sopra
    int indmax = 0;
    for (int i = 1; i<n; i++)
        if (v[i] > v[indmax]) indmax = i;       //aggiorna se trova un indice la cui entrata è maggiore
    return indmax;
}

void scambia_vettore(double v[], int x, int y){
    double temp;
    temp = v[x];
    v[x] = v[y];
    v[y] = temp;
    return;
}

void stampa_vettore(double v[], int n){
    for (int i = 0; i<n; i++)
        printf("[%lf]\n", v[i]);
    return;
}