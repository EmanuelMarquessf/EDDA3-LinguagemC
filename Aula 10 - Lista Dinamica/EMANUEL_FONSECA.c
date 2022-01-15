#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//Emanuel Fonseca -- CJ3005925

typedef struct sPessoa{
    char nome[50];
    int matricula;
}PESSOA;

typedef struct sCell{
    PESSOA info;
    struct sCell *next;
}CELULA;

CELULA* criarCelula(){
    CELULA *nova = (CELULA *) malloc(sizeof(CELULA));
    return nova;
}

void inicializarLista(CELULA **lista){
    (*lista) = NULL;
}

int listaVazia(CELULA **lista){
    if((*lista) == NULL){
        return 1;
    }
    return 0;
}

PESSOA inserirPessoa(){
    PESSOA p;
    printf("Entre com a matricula: \n");
    scanf("%d", &p.matricula);
    printf("Entre com o nome: \n");
    scanf(" %[^\n]", &p.nome);

    return p;
}

int inserirFim(CELULA **lista, PESSOA elemento){
    CELULA *novaCelula;
    CELULA *auxiliar;

    novaCelula = criarCelula();
    if(novaCelula == NULL){
        printf("\nERRO: Memoria Cheia");
        return 0;
    }

    novaCelula->info = elemento;
    novaCelula->next = NULL;

    if(listaVazia(lista)){
        (*lista) = novaCelula;
        return 1;
    }
    auxiliar = (*lista);
    while(auxiliar->next != NULL){
        auxiliar = auxiliar->next;
    }

    auxiliar->next = novaCelula;
    return 1;
}

int inserirInicio(CELULA **lista, PESSOA elemento){
    CELULA *novaCelula = criarCelula();
    if(novaCelula == NULL){
        printf("\nERRO: memoria cheia");
        return 0;
    }
    if(listaVazia(lista)){
        return inserirFim(lista, elemento);
    }
    novaCelula->info = elemento;
    novaCelula->next = (*lista);
    (*lista) = novaCelula;
    return 1;
}

void imprimirElemento(PESSOA elemento){
    printf("\nMatricula: %d \tNome: %s", elemento.matricula, elemento.nome);
}

void imprimirLista(CELULA **lista){
    CELULA *auxiliar = (*lista);
    if(listaVazia(lista)){
        printf("\nLista Vazia");
    }else{
        printf("\nLista: ");
        while(auxiliar != NULL){
            imprimirElemento(auxiliar->info);
            auxiliar = auxiliar->next;
        }
        printf("\n");
    }
}

PESSOA removerInicio(CELULA **lista){
    CELULA *removida;

    PESSOA removido;
    strcpy(removido.nome," ");
    removido.matricula = -1;

    if(listaVazia(lista)){
        printf("\nERRO: Lista vazia");
        return removido;
    }

    removida = (*lista);
    removido = removida->info;

    (*lista) = (*lista)->next;

    free(removida);
    return removido;
}


PESSOA removerFinal(CELULA **lista){
    CELULA *removida;
    CELULA *anterior;
    PESSOA removido = inserirPessoa(" ", -1);

    if(listaVazia(lista)){
        printf("\nErro: Lista Vazia");
        return removerInicio(lista);
    }
    if((*lista)->next == NULL){
        return removerInicio(lista);
    }
    removida = (*lista);
    while(removida->next != NULL){
        anterior = removida;
        removida = removida->next;
    }

    removido= removida->info;
    anterior->next = NULL;
    free(removida);
    return removido;
}

CELULA *pesquisarMatr(CELULA **lista, int mat){
    CELULA *auxiliar;

    if(listaVazia(lista)){
        printf("\nERRO: lista vazia");
        return NULL;
    }

    auxiliar = (*lista);
    while(auxiliar != NULL){
        if(auxiliar->info.matricula == mat)
            return auxiliar;
        auxiliar = auxiliar->next;
    }
    return NULL;
}

PESSOA removeMatr(CELULA **lista, int mat){
    CELULA *removida;
    CELULA *anterior;
    PESSOA pRemover = inserirPessoa(" ", -1);


    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia");
        return pRemover;
    }

    removida = pesquisarMatr(lista, mat);
    if(removida == NULL){
        printf("\nERRO: Matricula nao encontrada");
        return pRemover;
    }

    if(removida == (*lista)){
        return removerInicio(lista);
    }

    pRemover = removida->info;

    anterior = (*lista);

    while(anterior->next != removida){
        anterior = anterior->next;
    }

    anterior->next = removida->next;
    free(removida);
    return pRemover;
}

int main(){
    CELULA *ptrLista;
    inicializarLista(&ptrLista);

    inserirFim(&ptrLista, inserirPessoa());

    int opcao, mat;
    CELULA *q = criarCelula();

    do{
        printf("=========================================\n");
        printf("[0] - SAIR\n");
        printf("[1] - VERIFICAR SE VAZIA\n");
        printf("[2] - INSERIR PESSOA NO INICIO\n");
        printf("[3] - INSERIR PESSOA NO FIM\n");
        printf("[4] - IMPRIMIR LISTA DE PESSOAS\n");
        printf("[5] - REMOVER PESSOA NO INICIO\n");
        printf("[6] - REMOVER PESSOA NO FIM\n");
        printf("[7] - PESQUISAR POR MATRICULA\n");
        printf("[8] - REMOVER POR MATRICULA\n");
        printf("=========================================\n");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                if(listaVazia(&ptrLista))
                    printf("Lista Vazia!!");
                else
                    printf("Lista com elementos!!");
                break;
            case 2:
                inserirInicio(&ptrLista, inserirPessoa());
                break;
            case 3:
                inserirFim(&ptrLista, inserirPessoa());
                break;
            case 4:
                imprimirLista(&ptrLista);
                break;
            case 5:
                removerInicio(&ptrLista);
                break;
            case 6:
                removerFinal(&ptrLista);
                break;
            case 7:
                printf("Digite a matricula desejada: ");
                scanf("%d", &mat);
                if(pesquisarMatr(&ptrLista, mat))
                    printf("\nMatricula Encontrada!!\n");
                else
                    printf("\nMatricula nao Encontrada!!\n");
                break;
            case 8:
                printf("Digite a matricula desejada: ");
                scanf("%d", &mat);
                removeMatr(&ptrLista, mat);
                break;
        }
    }while(opcao != 0);
}


