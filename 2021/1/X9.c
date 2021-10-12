#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *readKey () {
    int i, buffer = 76; /* Largura da maior palavra na língua portuguesa */
    char c, *input = malloc(buffer * sizeof(*input));

    for (i = 0; (c = getchar()) != EOF && isalnum(c); i++) {
        if (i == buffer - 1) {
            buffer += buffer;
            input = realloc(input, buffer * sizeof(*input));
        }
        input[i] = c;
    }
    input[i] = '\0';
    return input;
}

int main () {
    int n = 0, i;
    char c,  *key, *zion = "rx47ziny3p9b01tw2vc8kmdoqjeg5lhfsua6";

    for (scanf("%d ", &n); n > 0; n--) {
        key = readKey();
        for (i = 0; key[i] != '\0'; i++) {
            c = getchar();
            if (c == key[i])
                continue;
            if (isalpha(c))
                printf("%c", zion[c - 'a']);
            else
                printf("%c", zion[26 + (c - '0')]);
        }
        printf("\n");
        scanf(" ");
    }
    return 0;
}

/*
10
ihdf9874basdbfjh9f23bhjlo ijdf0874aaswb07hxfzxbh1lx
sduhf34978hsdaf78234hbsdfogiof sdul03497vrsdff7g23w0bs8eogfxg
ghfwe978r4453kijdsf89g34kjsdfg ghofe9u8o4xuok08dvf89gx4knsdqi
5478544tr3egrwyuogy94e3lvdfyu9 5460544tg3e4rw8uony9qe3lidfyc9
aw3s4e6d5f76tg87yh5we86i afgz4e6d5f776g87ohfs8g04
sdfgrsdegerwt5gh34789thr98w7deap sd4grs8egeswtugh04a8jt0r918gdxf6
sx34wd4erv6tg7b54gfdhrt sxs7wdjexvgtw7864g4xjii
s4ed5rf6tg7yh456f8ta487 s4yd5rf7tg0yh4a6f8to4s7
zxhcvg9sergh7839r4fgwye7rga 1xhavg8sesg07736jgxfgye6ro8
fdghv92w4er8hfy34g77 l855fgffvj0a8oafe58368
*/
