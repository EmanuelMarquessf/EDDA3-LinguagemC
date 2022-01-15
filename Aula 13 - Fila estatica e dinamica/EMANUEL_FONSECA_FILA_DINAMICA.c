#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//Emanuel Fonseca -- CJ3005925

typedef struct sPessoa{
    char nome[50];
    int matricula;
}PESSOA;

typedef struct sCell{
    int info;
    struct sCell *next;
}CELULA;

typedef struct fila{
    CELULA *inicio;
    CELULA *fim;
}FILA;

void inicializarFila(FILA *fila){
    fila->inicio = NULL;
    fila->fim= NULL;
}

CELULA* criarCelula(){
    CELULA *nova = (CELULA *) malloc (sizeof(CELULA));
    return nova;
}

int filaVazia(FILA *fila){
    if(fila->inicio == NULL)
        return 1;
    return 0;
}

PESSOA criarPessoa(){
    PESSOA novaPes;
    printf("Entre com o nome da pessoa: \n");
    scanf(" %[^\n]", novaPes.nome);
    printf("Entre com a matricula: \n");
    scanf("%d", &novaPes.matricula);
    return novaPes;
}

int enfileirar(FILA *fila, PESSOA elemento){

    CELULA *nova = criarCelula();

    if(nova == NULL){
        printf("Nao foi possivel alocar!!\n");
        return 0;
    }
    nova->info = elemento;
    nova->next = NULL;

    if(filaVazia(fila)){
        fila->inicio = nova;
        fila->fim = nova;
        return 1;
    }

    (fila->fim)->next = nova;
    fila->fim = nova;
    return 1;
}

PESSOA primeiroFila(FILA *fila){
    PESSOA primeiro;
    primeiro.matricula = -1;

    if(filaVazia(fila)){
        printf("Nao existe ninguem na fila!\n");
        return primeiro;
    }
    primeiro = (fila->inicio)->info;
    return primeiro;
}

PESSOA desenfileirar(FILA *fila){
    PESSOA atendida;
    CELULA *auxiliar;

    atendida.matricula = -1;
    strcpy(atendida.nome, "");

    if(filaVazia(fila)){
        printf("Fila vazia \n");
        return atendida;
    }

    atendida = (fila->inicio)->info;
    auxiliar = (fila->inicio);
    (fila->inicio) = (fila->inicio)->next;
    free(auxiliar);
    return atendida;
}

imprimir(){

}

int main(){
    PESSOA aux;
    FILA f;
    inicializarFila(&f);
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
                if(filaVazia(&f))
                    printf("\nFila Vazia!!\n");
                else
                    printf("\nFila com elementos!!\n");
                break;
            case 3:
                enfileirar(&f, criarPessoa());
                break;
            case 4:
                desenfileirar(&f);
                break;
            case 5:
                imprimir(&f);
        }

    }while(opcao != 0);
}


