#include <stdio.h>
#include "./balance.c"

int main () {
    int i = 0;

    printf("Este programa recebe valores de volume e concentração de álcool para um par de barris, efetuando uma mistura que deixa um ou ambos os barris com concentração de 14 por cento de álcool.\n Digite quantos pares de barris pretende-se balancear: ");

    for (scanf(" %d", &i); i > 0; i--) {
        printf("\nDigite os valores de volume e concentração para ambos o barris do %dº par, respectivamente:\n", i + 1);
        switch (balance()) {
            case EOF:
                printf("Valores inválidos\n");
                return 1;
            case 0:
                printf("Assim n vai dar. A bebida tem que estar perfeita!\n");
                break;
            case 1:
                printf("Hehe, esse aqui ta no ponto. Guardem o barril 1 para depois\n");
                break;
            case 2:
                printf("Hehe, esse aqui ta no ponto. Guardem o barril 2 para depois\n");
                break;
            default:
                printf("Hehe, esse aqui ta no ponto.\n");
        }
    }
    return 0;
}
