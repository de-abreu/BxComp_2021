#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value, pos;
} Node;

void swap (Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort (Node * sequence, int size) {
    int i, pos = 0;

    if (size <= 1)
        return;
    for (i = 1; i < size; i++)
        if (sequence[i].value < sequence[pos].value)
                pos = i;
    swap(sequence, &sequence[pos]);
    selectionSort(sequence + 1, size - 1);
}

int main(){
    int n, i, size;
    Node * array;

    n = size = 0;
    for (scanf("%d\n%d", &n, &size); n > 0; n--) {
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
    }
    return 0;
}
