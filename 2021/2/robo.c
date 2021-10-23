#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readElement() {
    int i;
    char c;

    if (scanf(" %d", &i))
        return i;
    scanf(" %c", &c);
    return c;
}

int ** readMatrix (int l, int c) {
    int i, j, **matrix = malloc(l * sizeof(int *));

    matrix[0] = malloc(c * sizeof(int));
    matrix[0][0] = c;
    matrix[0][1] = l;
    for (i = 2; i < c; i++)
        matrix[0][i] = readElement();
    for (i = 1; i < l; i++) {
        matrix[i] = malloc(c * sizeof(int));
        for (j = 0; j < c; j++)
            matrix[i][j] = readElement();
    }
    return matrix;
}

void freeMatrix (int **matrix, int l) {
    int i;

    for (i = 0; i < l; i++)
        free (matrix[i]);
}

char * findFlavor (int **matrix, int l, int c, char food[30]) {
    int i, j, m, n;
    char *flavor = malloc(30 * sizeof(char));

    for (i = m = n = 0; i < c; i++) {
        for (j = 0; j < l; j++) {
            if (food[m] != '\0')
                if (matrix[j][i] == (int) food[m])
                    m++;
                else
                    m = (matrix[j][i] == (int) food[0]) ? 1 : 0;
            else {
                if (matrix[j][i] >= 65 && matrix[j][i] <= 90)
                    flavor[n++] = matrix[j][i];
                else {
                    flavor[n] = '\0';
                    freeMatrix(matrix, l);
                    return flavor;
                }
            }
        }
    }
    freeMatrix(matrix, l);
    return NULL;
}

int main () {
    int n, l, c;
    char food[30], *flavor;

    n = l = c = 0;
    for (scanf("%d", &n); n > 0; n--) {
        scanf("%s %d %d", food, &l, &c);
        flavor = findFlavor(readMatrix(l, c), l, c, food);
        if (!flavor)
            printf("Não foi possível determinar o sabor real de %s.\n", food);
        else if (strcmp(food, flavor) == 0)
            printf("Tá limpo!\n%s tem gosto de %s mesmo\n", food, flavor);
        else
            printf("Algum robo maldito mudou meu prato!!!\n%s tem sabor de %s\n", food, flavor);
        free(flavor);
    }
    return 0;
}
