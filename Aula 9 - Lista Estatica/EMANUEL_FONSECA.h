#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAM 10
//struct
//typedef struct sLista Lista;
//Inicializar a lista:
typedef struct Slista{
    char elem [MAX_TAM];
    int ultimo;
}Lista;

void inicializarLista(Lista *lista){
    lista->ultimo = -1;
}
//Formas para criar a variável do tipo Lista:

//Lista *lista = (Lista *) malloc (sizeof(Lista));
//inicializarLista(lista);

//OU

//Lista lista;
//inicializarLista(&lista);

//Verificar se a lista está cheia.

int listaCheia(Lista *lista){
    if(lista->ultimo == (MAX_TAM - 1)){
        return 1;
    }
    return 0;
}

//Verificar se a lista está vazia.

int listaVazia(Lista *lista){
    if(lista->ultimo == 0){
        return 1;
    }
    return 0;
}

//Inserir um elemento no fim da lista.

void inserirFim(Lista *lista){
    Lista lis;
    inicializarLista(&lis);

    printf("Digite o elemento: ");
    fflush(stdin);
    scanf("%c", &lista->elem[lista->ultimo]);
    fflush(stdin);
    lista->ultimo++;
    printf("\nSUCESSO!!\n");
}

//Modificar um elemento existente.

int modificarElemento(Lista *lista, int posicao, char elem){
    if(!listaVazia(lista)){
        if(posicao >= 0 && posicao < lista->ultimo + 1){
            lista->elem[posicao] = elem;
            return 1;
        }
    }
    return 0;
}

//Tamanho da lista

int tamanhoLista(Lista *lista){
    return lista->ultimo;
}


int exibirElemento(Lista *lista){
    int i;
    //Verifica se ta vazio
    if(listaVazia(lista)){
        printf("ERRO: Lista Vazia!!\n");
        return 0;
    }

    for(int i=0; i < lista->ultimo+1; i++){
        printf("Elemento[%d]: %c\n", i, lista->elem[i]);
    }
    printf("\n\n\n");
    return 1;
}
void inserirK(Lista *lista){
    int aux;
    Lista lis;
    inicializarLista(&lis);
    int posicao;
    printf("Digite a posicao desejada: ");
    scanf("%d", &posicao);
    if(posicao > lista->ultimo){
        aux = lista ->ultimo;
        lista->ultimo= lista->ultimo + posicao;
        for(int i=0; i<=posicao; i++){
            lista->elem[aux] = ' ';
        }

    }
    printf("Digite o elemento: ");
    fflush(stdin);
    scanf("%c", &lista->elem[posicao]);
    fflush(stdin);
    printf("\nSUCESSO!!\n");
}

void inverterLista(Lista *lista){
    Lista lis;
    inicializarLista(&lis);
    if(listaVazia(lista)){
        printf("ERRO: Lista Vazia!!\n");
    }
    else{
        int x, i=0;
        char aux1, aux2;
        x=tamanhoLista(lista);
        while(i != x){
            printf("i:%d x:%d", i, x-i);
            aux1 =lista->elem[i];
            aux2 =lista->elem[lista->ultimo-i];
            lista->elem[i] = aux2;
            lista->elem[lista->ultimo-i] = aux1;
            i++;
        }
    }
    printf("\nSUCESSO!!\n");
}


void ordenarLista(Lista *lista){
    Lista lis;
    inicializarLista(&lis);
    if(listaVazia(lista)){
        printf("ERRO: Lista Vazia!!\n");
    }
    else{
        int x,i;
        char aux1, aux2;
        x=tamanhoLista(lista);
        for(int i2=0; i2<4; i2++){
            i=0;
            while(i<x+1){
                if(lista->elem[i] > lista->elem[i+1]){
                    aux1=lista->elem[i];
                    aux2=lista->elem[i+1];
                    if(lista->elem[i+1]!=0){
                        lista->elem[i] = aux2;
                        lista->elem[i+1] = aux1;
                    }
                    else
                        i++;
                }else{
                    i++;
                }
            }
        }
    }
}



