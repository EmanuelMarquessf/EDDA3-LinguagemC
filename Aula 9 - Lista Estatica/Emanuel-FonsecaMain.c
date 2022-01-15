#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Emanuel-FonsecaLista.h"
#define MAX_TAM 10

//Emanuel Fonseca - CJ3005925

int main(){
    int opcao;
    char elemento[MAX_TAM];
    Lista *lista;
    Lista lis;

    do{
        printf("=========================================\n");
        printf("[1] Inserir Elemento\n");
        printf("[2] Insercao Elemento Posicao K\n");
        printf("[3] Exibir Fila\n");
        printf("[4] Inversao Fila\n");
        printf("[5] Ordenar Fila em ordem alfabetica\n");
        printf("=========================================\n");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                inserirFim(&lis);
                break;
            case 2:
                inserirK(&lis);
                break;
            case 3:
                exibirElemento(&lis);
                break;
            case 4:
                inverterLista(&lis);
                break;
            case 5:
                ordenarLista(&lis);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opcao != 99);
}


