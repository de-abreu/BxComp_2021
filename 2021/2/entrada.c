#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime (int num) {
    int i;

    if (num < 2)
        return false;
    for(i = 3; i < sqrt(num); i += 2)
        if(num % i == 0)
            return false;
    return true;
}

void countProducts() {
    int n1, n2, cod, p, np;
    p = np = 0;

    scanf(" %d %d", &n1, &n2);
    while (scanf(" %d", &cod) && cod != 0) {
        if(isPrime(cod))
            p++;
        else
            np++;
    }
    if ((n1 == p && n2 == np) || n1 + n2 == p || n1 + n2 == np)
        printf("ROGeRIO POH DEIXAR ESSX AQUI ENTRAR QUE TA LIMPO\n");
    else if (p == np && np == 0)
        printf("vei sem nada neah? vai gasta moh grana ai dentro\n");
    else
        printf("tu ta achando q vai pa onde co essas muamba ai? va vende isso noutro lugar\n");

}

int main(){
    int n = 0;

    for(scanf(" %d", &n); n > 0; n--)
        countProducts();
    return 0;
}
