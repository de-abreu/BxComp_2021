#include <stdbool.h>
#include <stdio.h>

#define EPSILON 0.000001

typedef struct {
    int no;
    float juice, alcohol;
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
            continue;
        }
        if (f > 1)
            return false;
        reservoir->alcohol += line[i / 2].alcohol = f * line[i / 2].juice;
        reservoir->juice += line[i / 2].juice -= line[i / 2].alcohol;
    }
    return true;
}

void sortLine(Barrel * line) {
    Barrel aux = line[0];

    if (line[0].juice + line[0].alcohol > line[1].juice + line[1].alcohol)
        return;
    line[0] = line[1];
    line[1] = aux;
}

int loadBarrel (Barrel * reservoir, Barrel b) {
    float capacity = b.juice + b.alcohol;

    if (reservoir->juice - capacity * 0.86 < -EPSILON
    || reservoir->alcohol - capacity * 0.14 < -EPSILON)
    return 0;

    reservoir->juice -= capacity * 0.86;
    reservoir->alcohol -= capacity * 0.14;
    return b.no;
}

int balance() {
    int i, result = 0;
    Barrel line[2], reservoir = {0};

    if (!readInput(line, &reservoir))
        return EOF;

    sortLine(line);

    for (i = 0; i < 2; i++)
        result += loadBarrel(&reservoir, line[i]);

    return result;
}
