/*Esercizio F6_1
    Scrivere un programma C++ che acquisisce da tastiera un numero intero positivo
    n ≤ 64, ne calcola e stampa sul video il fattoriale n!, la potenza n5 , l’approssimazio-
    ne con tolleranza 10−6 della radice quadrata n, e infine stampa n in base 2. Strut-
    turare il programma in funzioni (lettura_dato, controllo_dato, calcolo_fattoriale,
    potenza, approssimazione_radice, conversione_sistema_binario).

*/
#include <cstdio>
#define N 7                 //massima grandezza dell'array siccome 64 = 2^6
#define TOL 1.e-6           //tolleranza richiesta


int lettura_dato();

int controllo_dato(int);

double calcolo_fattoriale(int);

int potenza(int, int);

double approssimazione_radice(int);

int conversione_sistema_binario(int, int[]);


int main(void){

    int n; int bin[N];
    
    n = lettura_dato();

    if(!(controllo_dato(n))) {printf("\nNumero inserito non valido\n"); return 1;}
    
    printf("n!      --> %.0lf\nn^5     --> %d\nsqrt(n) --> %lf\nbase 2  --> ", calcolo_fattoriale(n), potenza(n, 5), approssimazione_radice(n));
    int i = conversione_sistema_binario(n, bin);

    while (i) printf("%d", bin[--i]); 
    printf("\n");
    return 0;
}

int lettura_dato(){
    int n;
    printf("Inserire un numero intero positivo (massimo 64) :");    
    scanf("%d", &n);
    return n;
}

int controllo_dato(int n){
    if(n <= 0 || n > 64) return 0;
    return 1;
}

double calcolo_fattoriale(int n){
    double fat = 1;
    //if (!n) return 1.;            //commentato perchè non capiterà mai grazie al controllo precedente 
    while (n) fat *= n--;
    return fat;
}

int potenza(int n, int e){
    int pot = 1;
    while (e--) pot *= n;
    return pot;
}

double approssimazione_radice(int a){           //algoritmo di Erone con con il valore della radice che parte da 8 
                                                //siccome è il massimo valore che può assumere dato che sqrt(64) = 8
    double temp, rd = 8;        
    do{
        temp = rd;
        rd = (rd + a/rd)/2;
    }while(temp - rd > TOL);
    return rd;
}

int conversione_sistema_binario(int n, int bin[]){      //restituisce il massimo indice dell'array + 1 per
    int i = 0, pos;                                     //stamparlo dopo
    while(n){
        pos = n%2;
        bin[i++] = pos;
        n /= 2;
    }
    return i;
}