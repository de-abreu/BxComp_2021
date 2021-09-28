#include <stdio.h>

int main () {
    int n = 0;
    char c;

    for (scanf("%d\n", &n); n > 0; n--) {
        while (scanf("%c", &c) && c != '\n') {
            switch (c) {
                case 'D':
                    printf("Rolada tatica ninja.\n");
                    break;
                case 'E':
                    printf("Esquerdei, e agora?\n");
                    break;
                case 'C':
                    printf("Eita pipoco. Zumm!\n");
                    break;
                case 'B':
                    printf("\n");
                    break;
                case 'F':
                    printf("Pronto e agora, e agora?\n");
                    break;
                case 'A':
                    printf("Nem ferrando. Vou de agentes mesmo.\n");
                    break;
            }
        }
    }
    return 0;
}
