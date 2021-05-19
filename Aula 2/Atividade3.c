#include<stdio.h>
/*
    Dado uma variável inteira chamada Segredo com o
    valor 42, faça um programa em que o usuário
    deverá chutar um valor e o programa deve informar
    se o valor é menor, maior ou igual ao Segredo.
    O programma só encerra quando acertar o valor do
    Segredo ou usuário digitar 0.
*/
int main(){
    int segredo=42, valor;
    do{
        printf("Digite seu numero: ");
        scanf("%d", &valor);
        if(valor>segredo){
            printf("Maior\n");
        }
        else if(valor<segredo && valor>0){
            printf("Menor\n");
        }
        else if(valor==segredo){
            printf("Igual\n");
        }
        else if(valor==0){
            printf("Desistiu");
            break;
        }
    }while(valor!=segredo);

return 0;
}
