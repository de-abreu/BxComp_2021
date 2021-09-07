#include <stdlib.h>

int balancear() {
    int i, barrels[4], sortedBarrels[4], reservoir[2], isBigger;

    for (i = 0; i < 4; i++)
        if (!scanf(" %f", barrels[i]) || barrels[i] <= 0)
            return -1;

    for (i = 0; i < 1; i++)
        reservoir[0] = barrels[0] + barrels[2];

    reservoir[1] = barrels[1] + barrels[3];

    sortedBarrels = sortBarrels(barrels)
    isBigger = (barrels[1] == sortedBarrels[1]) ? 1 : 2;

    for (i = 0; i < 4; i += 2) {

    }
}
