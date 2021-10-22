#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool closestPhone(int *x, int *y) {
    int phones, route_x, route_y;
    double distance, closest;

    if (!scanf(" %d", &phones) || phones <= 0)
        return false;

    scanf(" %d %d", x, y);
    closest = sqrt(pow(abs(5 - *x),2) + pow(abs(5 - *y),2));

    while (--phones > 0) {
        scanf(" %d %d", &route_x, &route_y);
        distance = sqrt(pow(abs(5 - route_x),2) + pow(abs(5 - route_y),2));
        if (distance > closest)
            continue;
        closest = distance;
        *x = route_x;
        *y = route_y;
    }
    return true;
}

int main () {
    int x, y, n = 0;

    for (scanf(" %d", &n); n > 0; n--) {
        if (!closestPhone(&x, &y))
            printf("Ihh rapaiz, foi muito bom te conhecer, F proceis.\n");
        else if (x == y && y == 5)
            printf("meu amigo olha o telefone ai do teu lado! Mas as coordenadas sao x = 5 e y = 5...\n");
        else
            printf("AHAAA achei, corre malucoo as coordenadas sao x = %d, y = %d\n", x, y);
    }
    return 0;
}
