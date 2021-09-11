#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int no;
    float juice, alcohool;
} Barrel;

int balancear() {
    int i, result;
    float f, capacity;
    Barrel line[2], sortedLine[2], * finalLine, reservoir;

    /* Read Input */
    for (i = 0; i < 4; i++) {
        if (!scanf(" %f", &f) || f <= 0)
            return EOF;
        if (i % 2 == 0) {
            line[i / 2].no = i / 2 + 1;
            line[i / 2].juice = f;
        }
        else {
            if (f > 1)
                return EOF;
            line[i / 2].alcohool = f * line[i / 2].juice;
            line[i / 2].juice -= line[i / 2].alcohool;
        }
        reservoir.juice = line[0].juice + line[1].juice;
        reservoir.alcohool = line[0].alcohool + line[1].alcohool;
    }

    /* Sort Line */
    if (line[0].juice + line[0].alcohool < line[1].juice + line[1].alcohool) {
        sortedLine[0] = line[1];
        sortedLine[1] = line[0];
        finalLine = sortedLine;
    }
    else
        finalLine = line;

    /* Load Barrels */
    for (i = 0; i < 2; i++) {
        capacity = finalLine[i].juice + finalLine[i].alcohool;
        if (reservoir.juice - capacity * 0.86 >= 0 &&
            reservoir.alcohool - capacity * 0.14 >= 0) {
            reservoir.juice -= capacity * 0.86;
            reservoir.alcohool -= capacity * 0.14;
            result += finalLine[i].no;
        }
    }

    return result;
}
