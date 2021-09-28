#include <stdio.h>

int resolve (char game[3][3], int * line) {
    int i, j;
    char win = 'O';

    for (i = 1; i < 3; i++) {

        /* Teste horizontal */
        for (j = 0; j < 9; j++) {
            if (game[j / 3][j % 3] != win)
                j += 2 - (j % 3);
            else if (j % 3 == 2) {
                if (win == 'V') {
                    j -= 2;
                    do {
                        line[j % 3] = 10 * (j / 3) + (j % 3) + 11;
                        game[j / 3][j % 3] = 'X';
                        j++;
                    } while(j % 3 != 0);
                }
                return i;
            }
        }

        /* Teste vertical */
        for (j = 0; j < 9; j++) {
            if (game[j % 3][j / 3] != win)
                j += 2 - (j % 3);
            else if (j % 3 == 2) {
                if (win == 'V') {
                    j -= 2;
                    do {
                        line[j % 3] = 10 * (j % 3) + (j / 3) + 11;
                        game[j % 3][j / 3] = 'X';
                        j++;
                    } while(j % 3 != 0);
                }
                return i;
            }
        }

        /* Caso diagonal direto */
        for (j = 0; j < 3; j++) {
            if (game[j][j] != win)
                break;
            if (j == 2) {
                if (win == 'V') {
                    for (j = 0; j < 3; j++) {
                        line[j] = 11 * j + 11;
                        game[j][j] = 'X';
                    }
                }
                return i;
            }
        }

        /* Caso diagonal inverso */
        for (j = 0; j < 3; j++) {
            if (game[2 - j][j] != win)
                break;
            if (j == 2) {
                if (win == 'V') {
                    for (j = 0; j < 3; j++) {
                        line[2 - j] = 10 * (2 - j) + j + 11;
                        game[2 - j][j] = 'X';
                    }
                }
                return i;
            }
        }
        win = 'V';
    }
    return 0;
}

int main () {
    int i, line[3], n = 0;
    char game[3][3];

    for (scanf("%d", &n); n > 0; n--) {
        for (i = 0; i < 9; i++)
            scanf(" %c", &game[i / 3][i % 3]);
        switch (resolve(game, line)) {
            case 0:
                printf("Bora outra valendo os dois Tic-Tac ?\n");
                break;
            case 1:
                printf("Tic-Tac de cereja eh bom tambem\n");
                break;
            default:
                printf("Hora de tirar o bafo\n%d-%d-%d\n", line[0], line[1], line[2]);
                for (i = 0; i < 9; i++) {
                    printf("%c ", game[i / 3][i % 3]);
                    if (i % 3 == 2)
                        printf("\n");
                }
        }
    }
    return 0;
}
