#include <stdio.h>

int main () {
    int n = 0, l1[2], l2[2];
    char p1, p2;

    for (scanf("%d\n", &n); n > 0; n--) {
        scanf(" %d,%d %d,%d", &l1[0], &l1[1], &l2[0], &l2[1]);
        if (l1[0] == 3 || l1[1] == 3 || l2[0] == 3 || l2[1] == 3){ /* casos vermelhos */
            printf("A casa caiu, Cleitinho! Soca PEM neles!\n");
            continue;
        }

        p1 = p2 = 'b';
        if (l1[0] > 1 && l1[0] < 5) /* casos amarelos topo */
            p1 = 'v';
        else if (l1[1] > 1 && l1[1] < 5)/* casos amarelos esquerda */
            p1 = 'h';
        if (l2[0] > 1 && l2[0] < 5) /* casos amarelos fundo */
            p2 = 'v';
        else if (l2[1] > 1 && l2[1] < 5) /* casos amarelos direita */
            p2 = 'h';

        if (p1 == 'b' && p2 == 'b')
            printf("Barra limpa, timeee\n");
        else if ((p1 == 'v' && p2 == 'h') || (p1 = 'h' && p2 == 'v'))
            printf("A casa caiu, Cleitinho! Soca PEM neles!\n");
        else if (p1 == 'h' || p2 == 'h')
            printf("Toca para horizontal, Tank.\n");
        else
            printf("Toca para vertical, Tank.\n");
    }
    return 0;
}
/* vermelho
0, 3
3, 0
6, 3
3, 6
Amarelo
0, 2
0, 4
2, 0
4, 0
6, 2
6, 4
2, 6
4, 6

hor 2-4
0,0 6,6 <- branco
0,1 5,6 <- branco
0,2 4,6 <- amarelo horizontal e vertical
0,3 3,6 <- vermelho horizonta vermelho vertical
0,4 2,6 <- amarelo vertical amarelo horizontal
0,5 1,6 < branco
0,6 0,6 <- branco
0,0 0,4 <- branco e amarelo
2,0 6,6 <- amarelo

Ambos brancos: Barra limpa, timeee
Amarelo ou vermelho horizontal ou vertical: A casa caiu, Cleitinho! Soca PEM neles!

*/
