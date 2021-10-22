#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 151

char ** readWords (int w) {
    int i;
    char **words = malloc(w * sizeof(char*));

    for (i = 0; i < w; i++) {
        words[i] = malloc(MAX * sizeof(char));
        scanf(" %s", words[i]);
    }
    return words;
}

bool isRepeated (char **words, int i, int size) {
    int j;

    if (strlen(words[i]) < 3
    || !strcmp(words[i], "uma")
    || !strcmp(words[i], "com")
    || !strcmp(words[i], "por")
    || !strcmp(words[i], "que")
    || !strcmp(words[i], "para"))
        return false;
    for (j = i + 1; j < size; j++)
        if (!strcmp(words[i],words[j]))
            return true;
    return false;
}

int countRepetitions (char **words, int size) {
    int i, repetitions = 0;

    for (i = 0; i < size - 1; i++) {
        if (isRepeated(words, i, size))
            repetitions++;
        free(words[i]);
    }
    free(words);
    return repetitions;
}

int main () {
    int size, n = 0;

    for (scanf(" %d", &n); n > 0; n--) {
        scanf(" %d", &size);
        printf("%d ocorrencia(s) de falha na matrix\n",
        countRepetitions(readWords(size), size));
    }
    return 0;
}
