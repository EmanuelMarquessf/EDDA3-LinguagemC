#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//Emanuel Fonseca -- CJ3005925

typedef struct sCell{
    int info;
    struct sCell *next;
}CELULA;

void inicializar(PILHA *pilha){
    pilha->topo = -1;
}

int pilhaVazia(PILHA *pilha){
    if(pilha->topo == -1){
        return 1;
    }
    return 0;
}

int pilhaCheia(PILHA *pilha){
    if(pilha->topo == (TAM-1)){
        return 1;
    }
    return 0;
}

int push (PILHA *pilha, int elemento){
    if(pilhaCheia(pilha)){
        printf("\nERRO! Pilha Cheia!!\n");
        return 0;
    }
    pilha->elem[pilha->topo+1] = elemento;
    pilha->topo++;
    return 1;
}

int pop(PILHA *pilha){
    int removido = -1;
    if(pilhaVazia(pilha)){
        printf("\nNao ha elementos para remover\n");
        return removido;
    }
    removido = pilha->elem[pilha->topo];
    pilha->topo--;
    return removido;
}

int topoEl(PILHA *pilha){
    int topo = -1;
    if(pilhaVazia(pilha)){
        printf("\nNao ha elemento.\n");
        return topo;
    }
    topo = pilha->elem[pilha->topo];
    printf("%d\n", topo);
    return topo;
}
int imprimirPilha(PILHA *pilha){
    int topo = -1;
    if(pilhaVazia(pilha)){
        printf("\nNao ha elemento.\n");
        return topo;
    }
    for(int i=0; i<=pilha->topo; i++){
        topo = pilha->elem[pilha->topo-i];
        printf("%d\n", topo);
    }
    return topo;
}

int main(){
    PILHA p;
    inicializar(&p);

    push(&p, 7);
    push(&p, 3);
    push(&p, 5);

    int opcao, numero;

    do{
        printf("=========================================\n");
        printf("[0] - SAIR\n");
        printf("[1] - VERIFICAR SE VAZIA\n");
        printf("[2] - VERIFICAR SE CHEIA\n");
        printf("[3] - INSERIR ELEMENTO\n");
        printf("[4] - REMOVER ELEMENTO\n");
        printf("[5] - EXIBIR ELEMENTO NO TOPO\n");
        printf("[6] - EXIBIR PILHA\n");
        printf("=========================================\n");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                if(pilhaVazia(&p))
                    printf("Pilha Vazia!!\n");
                else
                    printf("Pilha com elementos!!\n");
                break;
            case 2:
                if(pilhaCheia(&p))
                    printf("Pilha Cheia!!\n");
                else
                    printf("Pilha nao Cheia!!\n");
                break;
            case 3:
                printf("Digite o numero: ");
                scanf("%d", &numero);
                push(&p, numero);
                break;
            case 4:
                pop(&p);
                break;
            case 5:
                printf("\nTopo: ");
                topoEl(&p);
                break;
            case 6:
                printf("\nPilha:\n\n");
                imprimirPilha(&p);
                break;
        }
    }while(opcao != 0);
}


