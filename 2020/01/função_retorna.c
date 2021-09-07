int funcaoBalancear () {

    int n;
    float litro1, teor1, litro1, teor2;
    
    printf("Quantos barris você quer balancear?");
    scanf("%d", &n);

    if(!(scanf("%f %f %f %f", &litro1, &teor1, &litro2, &teor2)) || 
    (litro1 || teor1 || litro2 || teor2) <= 0) return 0;
        
}

int main () {

    funcaoBalancear();

}