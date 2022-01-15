#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define TAM 5

//Emanuel Fonseca -- CJ3005925

typedef struct fila{
    int elem[TAM];
    int cabecalho, ultimo;
}FILA;

void inicializar(FILA *fila){
    fila->ultimo = 0;
    fila->cabecalho = fila->ultimo;
}

int filaVazia(FILA *fila){
    return (fila->ultimo == fila->cabecalho);
}

int filaCheia (FILA *fila){
    int proxi = (fila->ultimo+1) %TAM;
    return (proxi == fila->cabecalho);
}

int enfileirar (FILA* fila, int elemento){
    int proxi;
    if(filaCheia(fila)){
        printf("\nFila Cheia!\n");
        return 0;
    }
    proxi = (fila->ultimo+1)%TAM;
    fila->elem[proxi] = elemento;
    fila->ultimo = proxi;
    return 1;
}
int desenfileirar (FILA* fila){
    int removido = -1;

    if(filaVazia(fila)){
        printf("\nFila Vazia!\n");
        return removido;
    }
    fila->cabecalho = (fila->cabecalho+1)%TAM;
    removido = fila->elem[fila->cabecalho];
    return removido;
}

void imprimir1(FILA *fila){
    int elemento;
    if(filaVazia(fila)){
        printf("\nFila vazia!\n");
        return;
    }
    printf("Fila:\t");
    do{
        elemento = desenfileirar(fila);
        printf("%d\t", elemento);
    }while(filaVazia(fila) != 1);
}

void imprimir2(FILA *fila){
    int elemento;
    FILA aux;
    if(filaVazia(fila)){
        printf("\nFila vazia!\n");
        return;
    }

    inicializar(&aux);

    printf("Fila:\t");
    do{
        elemento = desenfileirar(fila);
        printf("%d\t", elemento);
        enfileirar(&aux, elemento);
    }while(filaVazia(fila) != 1);

    do{
        elemento = desenfileirar(&aux);
        enfileirar(fila, elemento);
    }while(filaVazia(&aux) != 1);
}

int main(){
    FILA fila;
    inicializar(&fila);

    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);
    int opcao, numero;

    do{
        printf("=========================================\n");
        printf("[0] - SAIR\n");
        printf("[1] - VERIFICAR SE VAZIA\n");
        printf("[2] - VERIFICAR SE CHEIA\n");
        printf("[3] - INSERIR ELEMENTO\n");
        printf("[4] - REMOVER ELEMENTO\n");
        printf("[5] - EXIBIR FILA E DESENFILEIRAR\n");
        printf("[6] - EXIBIR FILA\n");
        printf("=========================================\n");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                if(filaVazia(&fila))
                    printf("\nFila Vazia!!\n");
                else
                    printf("\nFila com elementos!!\n");
                break;
            case 2:
                if(filaCheia(&fila))
                    printf("\nFila Cheia!!\n");
                else
                    printf("\nFila nao Cheia!!\n");
                break;
            case 3:
                printf("\nDigite o numero: ");
                scanf("%d", &numero);
                enfileirar(&fila, numero);
                break;
            case 4:
                desenfileirar(&fila);
                break;
            case 5:
                imprimir1(&fila);
                printf("\n");
                break;
            case 6:
                imprimir2(&fila);
                printf("\n");
                break;
        }
    }while(opcao != 0);
}
