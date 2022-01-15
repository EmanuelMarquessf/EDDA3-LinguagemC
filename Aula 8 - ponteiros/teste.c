#include<stdio.h>
#include<stdlib.h>

int Ex1(){
    int *n1, *n2;
    n1 = (int *) malloc(sizeof(int));
    n2 = (int *) malloc(sizeof(int));
    printf("Digite o numero 1: ");
    scanf("%d", &n1);
    printf("Digite o numero 2: ");
    scanf("%d", &n2);
    printf("Numero 1: %d\n", n1);
    printf("Numero 2: %d\n", n2);

    return main();
}

int Ex2(){
    int n, *vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    vetor = malloc(n * sizeof(int));
    for(int i=0;i<=n;i++){
        printf("Digite o numero do vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    for(int i=0;i<=n;i++){
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
    return main();
}
typedef struct cliente{
char nome[20];
int idade, telefone;
}CLIENTE;

//int Ex3(){}

int main(){
    CLIENTE *cli;
    int n;
    printf("Digite a quantidade de clientes: ");
    scanf("%d", n);
    cli = (CLIENTE*) malloc(n * sizeof(CLIENTE));
    for(int i=0;i<=n;i++){
        printf("Vetor[%d]: ", i);
        scanf("%^\n", cli[i].nome);
    }
    printf("%c", cli[1].nome);
    return main();
}
