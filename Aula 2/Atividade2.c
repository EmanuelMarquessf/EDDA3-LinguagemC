#include<stdio.h>
/*
    Fa�a um programa leia n�meros do teclado enquanto forem
diferentes de zero e apresente o somat�rio dos valores
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
