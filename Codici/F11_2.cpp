/*Esercizio F11_2
    Scrivere un programma C++ strutturato in funzioni che, definita la costante T ,
    a) calcola il grado necessario a garantire che l’approssimazione fornita dal polino-
    mio di Taylor di cos(T π), con x0 = 0, sia accurata entro la tolleranza τ acquisita
    da tastiera facendo uso del criterio di arresto a posteriori discusso a lezione; suc-
    cessivamente stampa sul video il valore cos(T π), il grado effettivo n0 del polinomio
    costruito e l’approssimazione calcolata.
    b) stampa su video sia l’approssimazione di cos(T π) realizzata facendo uso del
    polinomio interpolatore determinato dalla tavola della funzione coseno relativa agli
    n0 + 1 nodi (*) che dividono [0, π/2] in intervalli di uguale ampiezza che l’errore.
    Confrontare l’output del programma nei casi T = 0.1 e T = 0.4, avendo inserito
    in entrambi i casi prima τ = 10−3 e poi τ = 10−10 .
*/

#include <cstdio>
#include <cmath>
#define T 0.4       //assumo T <= 0.5 altrimenti bisognerebbe implementare le trasformazioni sotto nel polinomio di Taylor e simili nel polinomio interpolatore




double funzione(double);

int cos_Tpi(double, double&, double);

double input_tau();

void nodi_eq(double, double, double[], int);

double p_inter_Lagrange(double, double[], int);

double err(double, double);

int main(void){
    double y;
    double tau = input_tau();
    
    int g = cos_Tpi(T, y, tau);

    /*stampa grado g e approssimazione di Taylor*/

    printf("cos(T*pi) --> %.16lf\n\nGrado del polinomio di Taylor --> %d\nApprossimazione con polinomio di Taylor --> %.16lf\nErrore --> %e\n", funzione(T), g, y, err(T, y)); 
    
    double nodi[g+1];       //devo inizializzare dopo l'array perchè non so quanti nodi ho

    nodi_eq(0, M_PI/2, nodi, g);            //genera i nodi equidistanti

    y = p_inter_Lagrange(T, nodi, g);       //calcola il polinomio interpolatore

    /*stampa approssimazione con polinomio interpolatore ed errore commesso */

    printf("\nApprossimazione con polinomio interpolatore --> %.16lf\nErrore --> %e\n", y, err(T, y));
    return 0;
}


double funzione(double x){
    return cos(x*M_PI);
}

int cos_Tpi(double x, double& y, double tau){
    int cont = 0; double pot = 1, fact = 1, delta;
    
    /*if (x > 2){y = INFINITY; return 0;}
                                                                
    if(x > .5 && x <= 1){ x = 1 - x; s = 1;}                //trasformazioni per il calcolo del cos di un qualsiasi numero macchina in(-2^31-1, 2^31+1) intervallo aperto
    else if(x > 1 && x <= 1.5){ x = x - 1; s = 1;}
    else if(x > 1.5){ x = 2 - x;}
    */
    
    y = 1; x *= M_PI; x = -x*x;
    do{
        fact *= ++cont *(cont+1); cont++;
        pot *= x;
        delta = pot/fact;
        y += delta;
    }while(delta <= -tau || delta >= tau);

    //if(s) y = -y;                     //cambio di segno dovuto alle trasformazioni

    return cont;        //grado polinomio di grado maggiore di 2 rispetto al necessario
}


double input_tau(){
    double tau;
    do{
        printf("Inserire la tolleranza desiderata ( 0 < tau): ");
        scanf("%lf", &tau);
        if (tau <= 0)
            printf("Reinserire.\n");
    }while(tau <= 0);
    return tau;
}

void nodi_eq(double a, double b, double nodi[], int n){
    double m = (b-a)/n;
    nodi[0] = a;
    nodi[n] = b;                     
    for (int i = 1; i < n; i++)
        nodi[i] = nodi[i-1] + m;
    return;
}

double p_inter_Lagrange(double x, double nodi[], int n){
    double l_i, p_x = 0; x *= M_PI;                              //approssimo la funzione coseno ma devo in realtà calcolare cos(T*pi)
    for(int i = 0; i <= n; i++){
        l_i = 1;
        for (int j = 0; j <= n; j++)
            if(i != j)                                          //controlla che i nodi non siano uguali
                l_i *= (x-nodi[j])/(nodi[i]-nodi[j]);           //calcola il polinomio fondamentale riferito a ogni nodo
        p_x += cos(nodi[i]) * l_i;                              //calcola il polinomio interpolatore in forma di Lagrange che approssima la fuznione coseno
    }
    return p_x;
}

double err(double x, double y){
    return funzione(x) - y;
    
}