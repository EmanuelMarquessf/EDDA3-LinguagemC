#include<stdio.h>
/*
    Faça um programa leia números do teclado enquanto forem
diferentes de zero e apresente o somatório dos valores
no final.
*/
int main(){
    int numero,soma;
    do{
        printf("Digite o numero: ");
        scanf("%d", &numero);
        soma+=numero;
    }while(numero!=0);
    printf("%d", soma);
return 0;
}
