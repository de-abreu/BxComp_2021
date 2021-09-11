#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int no;
    float juice, alcohool;
} Barrel;

int balancear() {
    int i, barrels[4], sortedBarrels[4], reservoir[2], isBigger;

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

<<<<<<< HEAD
    sortedBarrels = sortBarrels(barrels);
    isBigger = (barrels[1] == sortedBarrels[1]) ? 1 : 2;

    Barrel * sortedLine[2];
    *sortedLine[0] = *line[1];
    *sortedLine[1] = *line[0];
    return sortedLine;
}

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
