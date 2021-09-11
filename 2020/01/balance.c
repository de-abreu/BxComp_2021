#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define EPSILON 0.000001

typedef struct {
    int no;
    float juice, alcohool;
} Barrel;

bool readInput(Barrel * line, Barrel * reservoir) {
    int i;
    float f;

    for (i = 0; i < 4; i++) {
        if (!(scanf(" %f", &f)) || f <= 0)
            return false;
        if (i % 2 == 0) {
            line[i / 2].no = i / 2 + 1;
            line[i / 2].juice = f;
        }
        else {
            if (f > 1)
                return false;
            line[i / 2].alcohool = f * line[i / 2].juice;
            line[i / 2].juice -= line[i / 2].alcohool;
        }
        reservoir->juice = line[0].juice + line[1].juice;
        reservoir->alcohool = line[0].alcohool + line[1].alcohool;
    }
    return true;
}

void sortLine(Barrel * line) {
    Barrel aux;
    if (line[0].juice + line[0].alcohool > line[1].juice + line[1].alcohool)
        return;
    aux = line[0];
    line[0] = line[1];
    line[1] = aux;
}

int loadBarrel (Barrel * reservoir, Barrel b) {
    float capacity = b.juice + b.alcohool;

    if (reservoir->juice - capacity * 0.86 >= -EPSILON
    && reservoir->alcohool - capacity * 0.14 >= -EPSILON) {
        reservoir->juice -= capacity * 0.86;
        reservoir->alcohool -= capacity * 0.14;
        return b.no;
    }
    return 0;
}

int balance() {
    int i, result = 0;
    Barrel line[2], reservoir;

    if (!readInput(line, &reservoir))
        return EOF;

    sortLine(line);

    for (i = 0; i < 2; i++)
        result += loadBarrel(&reservoir, line[i]);

    return result;
}
