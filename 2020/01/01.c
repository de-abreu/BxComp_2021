#include<stdio.h>

void mistura_barril (float x1, float y1, float x2, float y2) {
    float x3, y3;
    float porc;
    float z;
    porc = ((y1*x1) + (y2*x2))/(x1 + x2);
    //x3 = x1 + x2;
    y3 = porc;
    if(y3 < 0.14){
        if(x1 > x2){
            z = ((x2*y2) - 0.14*x2)/(0.14 - y1);
            printf("valor de z: \n", z);
        }
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