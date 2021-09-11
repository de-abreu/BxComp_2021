#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int no;
    float juice, alcohool;
} Barrel;

bool readInput(Barrel * line[2], Barrel * reservoir) {
    int i;
    float f;

    for (i = 0; i < 4; i++) {
        if (!scanf(" %f", &f) || f <= 0)
            return false;
        if (i % 2 == 0) {
            line[i / 2]->no = i / 2 + 1;
            line[i / 2]->juice = f;
        }
        else {
            if (f > 1)
                return false;
            line[i / 2]->alcohool = f * line[i / 2]->juice;
            line[i / 2]->juice -= line[i / 2]->alcohool;
        }
        reservoir->juice = line[0]->juice + line[1]->juice;
        reservoir->alcohool = line[0]->alcohool + line[1]->alcohool;
    }
    return true;
}

Barrel * sortLine(Barrel * line) {
    if (line[0].juice + line[0].alcohool > line[1].juice + line[1].alcohool)
        return line;

    Barrel * sortedLine[2];
    *sortedLine[0] = *line[1];
    *sortedLine[1] = *line[0];
    return sortedLine;
}

int loadBarrel (Barrel * reservoir, Barrel barrel) {
    float capacity = barrel.juice + barrel.alcohool;
    if (reservoir->juice - capacity * 0.86 >= 0 &&
        reservoir->alcohool - capacity * 0.14 >= 0) {
        reservoir->juice -= capacity * 0.86;
        reservoir->alcohool -= capacity * 0.14;
        return barrel.no;
    }
    return 0;
}

int balancear() {
    int i, result;
    Barrel line[2], reservoir;

    if (!readInput(&line, &reservoir))
        return EOF;

    line = sortLine(line);

    for (i = 0; i < 2; i++)
        result += loadBarrel(&reservoir, line[i]);

    return result;
}
