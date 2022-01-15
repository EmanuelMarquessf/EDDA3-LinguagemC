#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "lista.h"
#define MAX_TAM 10

int main(){
    int opcao;
    char elemento[MAX_TAM];
    Lista *lista;
    Lista lis;

    do{
        printf("=========================================\n");
        printf("[1] Inserir Elemento\n");
        printf("[2] Insercao Aleatoria\n");
        printf("[3] Insercao Elemento Posicao K\n");
        printf("[4] Exibir Fila\n");
        printf("[5] Inversao Fila\n");
        printf("[6] Ordenar Fila em ordem alfabetica\n");
        printf("=========================================\n");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                inserirFim(&lis);
                break;
            case 2:
                inserirFimRand(&lis);
                break;
            case 3:
                inserirK(&lis);
                break;
            case 4:
                exibirElemento(&lis);
                break;
            case 5:
                inverterLista(&lis);
                break;
            case 6:
                ordenarLista(&lis);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opcao != 7);
}


