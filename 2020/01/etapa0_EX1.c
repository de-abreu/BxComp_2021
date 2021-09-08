#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct {
    
    float litros;
    float conc;
}
Barril;



int main(){

    Barril b1, b2;
    int pares, i; 
    float litros, teor, utilizado, alc1, alc2;

    i = 1;

    scanf("%d", &pares);

    while (i <= pares){

        scanf("%f %f %f %f", &b1.litros, &b1.conc, &b2.litros, &b2.conc);
        
         alc1 = b1.litros * b1.conc;
         alc2 = b2.litros * b2.conc;

        if (b1.conc <= b2.conc){

            utilizado = 0.14 * (b1.litros + b2.litros) - alc1;

            if (utilizado + 0.0001 > alc2 && utilizado - 0.0001 < alc2){

                printf("Hehe, esse aqui ta no ponto.\n");
                i++;
                continue;

            }


            if (utilizado > alc2){

                printf("Assim n vai dar. A bebida tem que estar perfeita!\n");

            }
                

            if (utilizado < alc2){

                printf("Hehe, esse aqui ta no ponto. Guardem o barril 2 pra depois.\n");

            }

        }

        if (b1.conc > b2.conc){

            utilizado = 0.14 * (b1.litros + b2.litros) - alc2;

            printf("%f\n", utilizado);
            printf("%f\n", alc1);


            if (utilizado + 0.0001 > alc1 && utilizado - 0.0001 < alc1){

                printf("Hehe, esse aqui ta no ponto.\n");
                i++;
                continue;

            }


            if (utilizado > alc1){

                printf("Assim n vai dar. A bebida tem que estar perfeita!\n");

            }

            if (utilizado < alc1){

                printf("Hehe, esse aqui ta no ponto. Guardem o barril 1 pra depois.\n");

            }
        }

        ++i;
    }

    return 0;
}