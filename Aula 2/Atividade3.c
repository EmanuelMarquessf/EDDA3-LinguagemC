#include<stdio.h>
/*
    Dado uma vari�vel inteira chamada Segredo com o
    valor 42, fa�a um programa em que o usu�rio
    dever� chutar um valor e o programa deve informar
    se o valor � menor, maior ou igual ao Segredo.
    O programma s� encerra quando acertar o valor do
    Segredo ou usu�rio digitar 0.
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
