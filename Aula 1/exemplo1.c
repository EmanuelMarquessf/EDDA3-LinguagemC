#include<stdio.h>
#include<locale.h>          //Para passar para o padrão da linguamge do PC, no caso PT/BR

int main(){
    setlocale(LC_ALL, "");  //Para passar para o padrão da linguamge do PC, no caso PT/BR (usar acentuação)
    int valor, quadrado;
    float numeroReal;
    char caractere;

    printf("Entre com um valor inteiro: ");
    scanf("%d", &valor);

    //printf("Entre com um valor fracionario: ");
    //scanf("%f", &numeroReal);

    //fflush(stdin); //Limpar o buffer(para conseguir inserir um caractere ou string)

    //printf("Entre um char: ");
    //scanf("%c", &caractere);

    // Estruturas condicionais

    if(valor > 0 && valor < 10){
        //instrução
        quadrado = valor * valor;
        printf("O resultado do quadrado e: %d\n", quadrado);
        if(valor < 5)
            printf("Valor menor que 5\n");
        else if(valor=5)
            printf("Valor igual a 5\n");
        else
            printf("Valor maior que 5\n");
    }
    else{
        printf("Esta no intervalo");
    }
    if(valor == 1 || valor == 2){
        //instrução
        printf("O resultado e igual a: %d\n", valor);
    }

    switch(valor){
    case 1:
        printf("Numero 1\n");
        break;
    case 2:
        printf("Numero 2\n");
        break;
    case 3:
        printf("Numero 3\n");
        break;
    case 4:
        printf("Numero 4\n");
        break;
    default:
        printf("Outro Numero\n");
    }

    printf("O numero real e: %.2f\n", numeroReal);
    printf("O caractere e: %c\n", caractere);


    return 0;
}
