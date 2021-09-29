#include <stdio.h>
#include <ctype.h>

int main(){
    int n;
    char c, output;

    for (scanf("%d\n", &n); n > 0; n--) {
        while (scanf("%c", &c) != EOF && !iscntrl(c)) {
            if (c == ' ') {
                printf(" ");
                continue;
            }
            output = 'A' + 5 * (c - '0');
            scanf("%c", &c);
            output += (c - '0');
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
        scanf(" ");
        printf("\n");
    }
    return 0;
}
