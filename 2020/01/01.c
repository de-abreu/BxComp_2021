#include<stdio.h>

float mistura_barril (float x1, float y1, float x2, float y2) {

    if(y1 + y2 >= 0.14) {

        if (y1 > y2 && (y1 - y2) > 0) { //Caso o teor do 1º seja maior e saber qual tem mais 
            printf("Hehe, esse aqui ta no ponto.  Guardem o barril 1 pra depois.\n");
        } else if (y2 > y1 && (y2 - y1) > 0) {
            printf("Hehe, esse aqui ta no ponto.  Guardem o barril 2 pra depois.\n");
        } else if (y1 + y2 == 0.14) {
            printf("Hehe, esse aqui ta no ponto.\n");
        }

    } else {
        printf("Assim n vai dar.  A bebida tem que estar perfeita!\n");
    }

}


int main () {

    int par_barril;

    float barril1, barril2, teor1, teor2;

    printf("Quantos pares de barril:");
    scanf("%d", &par_barril);

    // for(int i=1; i <= par_barril; i++) {
        scanf("%f %f %f %f", &barril1, &teor1, &barril2, &teor2);
        mistura_barril(barril1, teor1, barril2, teor2);
    // }

    return 0;
}