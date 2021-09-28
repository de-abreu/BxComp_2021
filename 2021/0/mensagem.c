#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char c1, c2, output;

    for(scanf("%d\n", &n); n > 0; n--) {
        while (scanf("%c", &c1) && c1 != '\n') {
            if (c1 == ' ') {
                printf(" ");
                continue;
            }
            scanf("%c", &c2);
            output = 'A' + 5 * (c1 - '0') + (c2 - '0');
            if (output <= 'Z'){
                printf("%c", output);
                continue;
            }
            switch (output) {
                case 'Z' + 1:
                    printf(",");
                    break;
                case 'Z' + 2:
                    printf(".");
                    break;
                case 'Z' + 3:
                    printf("?");
                    break;
                default:
                    printf("!");
            }
        }
        printf("\n");
    }
    return 0;
}
