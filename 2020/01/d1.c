#include <stdio.h>
#include <stdlib.h>

int main(){
    float teor_al1, teor_al2;
    float vinho1, vinho2, porc;
    int N; // número de pares de barris
    scanf("%f", &N);
    for(int i = 0; i < N; i++){
        scanf("%f, %f, %f %f", &vinho1, &teor_al1, &vinho2, &teor_al2);
    }
    porc = (teor_al1 * vinho1 + teor_al2 * vinho1)/(vinho1 + vinho2);
    
    



    return 0;
}