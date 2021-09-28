#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value, pos;
} Node;

void selectionSort(Node * sequence, int size) {
    int i, j, pos;
    Node aux;

    for (i = 0; i < size - 1; i++) {
        pos = i;
        for (j = i + 1; j < size; j++)
            if (sequence[j].value < sequence[pos].value)
                pos = j;
        aux = sequence[i];
        sequence[i] = sequence[pos];
        sequence[pos] = aux;
    }
}

int main(){
    int n, i, size;
    Node * array;

    n = size = 0;
    scanf("%d\n%d", &n, &size);
    while (n > 0) {
        array = malloc(size * sizeof(*array));
        for (i = 0; i < size; i++) {
            array[i].pos = i;
            scanf("%d", &array[i].value);
        }
        selectionSort(array, size);
        for (i = 0; i < size; i++)
            printf("%d-%d ", array[i].value, array[i].pos);
        printf("\n");
        free(array);
        n--;
    }
    return 0;
}
