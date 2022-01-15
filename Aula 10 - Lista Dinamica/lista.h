#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int inserirFim(CELULA **LISTA, PESSOA elemento){
    CELULA *novaCelula;
    CELULA *auxiliar;

    novaCelula = criarCelula();
    if(novaCelula==NULL){
        printf("\nERRO: Memoria Cheia");
        return 0;
    }
    novaCelula->info = elemento;
    novaCelula->next = NULL;

    if(listaVazia(lista)){
        (*lista) = novaCelula;
        return 1;
    }

    auxiliar= (*lista);

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
            imprimirElmento(auxiliar->info);
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
    PESSOA removido = criarPessoa(" ", -1);

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

PESSOA removerMatr(CELULA **lista, int mat){
    CELULA *removida;
    CELULA *anterior;

    PESSOA pesRemovida;
    pesRemovida.matricula = -1;
    strcpy(pesRemovida.nome, " ");

    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia");
        return pesRemovida;
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











































































}



