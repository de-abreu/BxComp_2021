<<<<<<< HEAD
#include <stdio.h>
#include "./balancear.c"

int main () {
    int i, n;

    printf("Este programa recebe valores de volume e concentração de álcool para um par de barris, efetuando uma mistura que deixa um ou ambos os barris, com concentração de 14 por cento de álcool\n Digite quantos barris pretende-se balancear: ");
    if (!scanf(" %d", &n) || n <= 0) {
        printf("Valor inválido\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nDigite os valores de volume e concentração para ambos o barris do %dº par, respectivamente: ", i);
        switch (funcaoRetorna()) {
            case -1:
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
            case 3:
                printf("Hehe, esse aqui ta no ponto.\n");
        }
    return 0;
    }

}
=======
#include <stdio.h>
#include "./balancear.c"

int main () {
    int i, n;

    printf("Este programa recebe valores de volume e concentração de álcool para um par de barris, efetuando uma mistura que deixa um ou ambos os barris com concentração de 14 por cento de álcool.\n Digite quantos barris pretende-se balancear: ");
    if (!scanf(" %d", &n) || n <= 0) {
        printf("Valor inválido\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nDigite os valores de volume e concentração para ambos o barris do %dº par, respectivamente: ", i);
        switch (funcaoRetorna()) {
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
    return 0;
    }

}
>>>>>>> 4849a2b91d54f6115537c6396003ce1be6db6827
