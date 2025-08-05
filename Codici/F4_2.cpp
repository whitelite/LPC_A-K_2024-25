/*Esercizio F4_2
    Scrivere un programma C++ che implementa l’algoritmo di Archimede (sia nella
    versione originale che nella versione stabile), stampa sul video - visualizzandone
    sedici cifre significative - le approssimazioni di π ottenute dal calcolo del semiperi-
    metro dei poligoni regolari di 2k+2 lati inscritti nel cerchio di raggio unitario, con
    0 ≤ k ≤ 25, e confronta l’ultima stima per difetto ottenuta sia con la stima per
    eccesso data dal semiperimetro del corrispondente poligono regolare circoscritto al
    cerchio di raggio unitario che con la costante ‘M_PI’.
*/

#include <cstdio>
#include <cmath>

int main(void){
    double per_inscrit_inst, per_inscrit_stab, per_circo_inst, per_circo_stab, lato_inscrit_inst = M_SQRT2, lato_inscrit_stab = M_SQRT2, lato_circo_inst, lato_circo_stab; int k = 1, lati = 2;  //inizializzo i lati a 2 in modo da non avere problemi con il ciclo


    per_inscrit_inst = lato_inscrit_inst * lati;          //instabile
    per_inscrit_stab = lato_inscrit_stab * lati;          //stabile

    printf("Approssiamzione per il poligono inscritto con 2^%d lati(instabile) --> %.15lf\n", 2, per_inscrit_inst);
    printf("Approssiamzione per il poligono inscritto con 2^%d lati(stabile)   --> %.15lf\n\n", 2, per_inscrit_stab);
    
    do{
        lati *= 2;
        
        lato_inscrit_inst = sqrt( 2 - sqrt( 4  - lato_inscrit_inst * lato_inscrit_inst));                            //instabile
        lato_inscrit_stab = lato_inscrit_stab / (sqrt( 2 + sqrt( 4 - lato_inscrit_stab * lato_inscrit_stab)));       //stabile
        
        per_inscrit_inst = lato_inscrit_inst * lati;
        per_inscrit_stab = lato_inscrit_stab * lati;
        
        printf("Approssiamzione per il poligono inscritto con 2^%d lati(instabile) --> %.15lf\n", k+2, per_inscrit_inst);
        printf("Approssiamzione per il poligono inscritto con 2^%d lati(stabile)   --> %.15lf\n\n", k+2, per_inscrit_stab);
        
    }
    while(++k < 26);
    
    lato_circo_inst = 2 * lato_inscrit_inst / sqrt( 4 - lato_inscrit_inst*lato_inscrit_inst); per_circo_inst = lato_circo_inst * lati;     //instabile
    lato_circo_stab = 2 * lato_inscrit_stab / sqrt( 4 - lato_inscrit_stab*lato_inscrit_stab); per_circo_stab = lato_circo_stab * lati;     //stabile
    
    printf("Differenza della stima per difetto con la stima per eccesso e M_PI (instabile):\n -  %.15lf\n -   %.15lf\n", per_inscrit_inst - per_circo_inst, per_inscrit_inst - M_PI);
    printf("Differenza della stima per difetto con la stima per eccesso e M_PI (stabile):\n -  %.15lf\n -   %.15lf\n\n", per_inscrit_stab - per_circo_stab, per_inscrit_stab - M_PI);
    return 0;
}