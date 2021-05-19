#include<stdio.h>

int main(){
    int valor, i=0, fatorial=1;
    printf("Digite um numero: ");
    scanf("%d", &valor);
    /*

    for(int i=0 ; i < valor-1 ; i++)
        fatorial =fatorial*(valor-i);
    printf("%d\n", fatorial);

    int i=0;
    while(i<valor-1){
        fatorial =fatorial*(valor-i);
        printf("%d\n", fatorial);
        i++;
    }
    */
    do{
        fatorial =fatorial*(valor-i);
        printf("%d\n", fatorial);
        i++;
    }while(i<valor-1);

    return 0;
}
