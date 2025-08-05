/* Esercizio F1_1
Convertitore da gradi Fahrenheit a gradi Celsius .
Input : si richiede la misura in gradi Fahrenheit .
Output : si fornisce la misura in gradi Celsius . */


#include <stdio.h>

int main(void){
    float temp;
    printf("Temperatura in gradi Fahreneit: ");
    scanf("%f", &temp);
    temp = (temp-32)*5/9;
    printf("Temperatura in gradi Celsius: %f\n", temp);
    return 0;
}