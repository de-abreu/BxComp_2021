#include <stdio.h>

int main () {
    int pares[2] = {0}, n, m, i, j, valor;

    n = m = j = 0;
    for (scanf("%d\n%d\n", &n, &m); n > 0; n--) {
        for (i = 0; i < m; i++) {
            scanf(" %d", &valor);
            if (valor % 2 == 0) {
                pares[j] = valor;
                j = (j + 1) % 2;
                printf("%d ", valor * i);
            }
            else
                printf("%d ", pares[0] + pares[1]);
        }
        printf("\n");
    }
    return 0;
}
