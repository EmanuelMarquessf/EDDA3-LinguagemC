#include<stdio.h>
#include<stdlib.h>

//Emanuel Fonseca -- CJ3005925

typedef struct sNode{
    int info;
    struct sNode *esq;
    struct sNode *dir;
}NO;

int arvoreVazia(NO **raiz){
    if((*raiz) == NULL)
        return 1;
    return 0;
}

NO* criarNo(){
    NO *novo = (NO*) malloc(sizeof(novo));
    return novo;
}

void inserirRecursivo(NO **raiz, int elemento){
    NO *novo = criarNo();

    if(novo == NULL)
        return;

    novo->info = elemento;
    novo->esq = NULL;
    novo->dir = NULL;

    if(arvoreVazia(raiz)){
        (*raiz) = novo;
        return;
    }

    if(novo->info < (*raiz)->info)
        inserirRecursivo(&((*raiz)->esq), elemento);
    else if(novo->info >= (*raiz)->info)
        inserirRecursivo(&((*raiz)->dir), elemento);

    return;
}

int inserir(NO **raiz, int elemento){
    NO *novo;
    novo = criarNo();

    if(novo == NULL)
        return 0;
    novo->info = elemento;
    novo->esq = NULL;
    novo->dir = NULL;

    if(arvoreVazia(raiz)){
        (*raiz) = novo;
        return 1;
    }
    NO *aux = (*raiz);
    NO *anterior = NULL;

    while(aux != NULL){
        anterior = aux;
        if(elemento >= aux->info)
            aux = aux->dir;
        else
            aux = aux->esq;
    }
    if(elemento >= anterior->info)
        anterior->dir = novo;
    else
        anterior->esq = novo;
    return 1;
}

NO* pesquisar (NO *raiz, int elemento){
    if(raiz == NULL)
        return NULL;
    if(raiz->info == elemento)
        return raiz;
    else if(raiz->info > elemento)
        return pesquisar(raiz->esq, elemento);
    else
        return pesquisar(raiz->dir, elemento);
}

NO* maiorElemento(NO **rz){
    if((*rz)->dir != NULL)
        return maiorElemento(&(*rz)->dir);
    else{
        NO *aux = *rz;
        if((*rz)->esq !=NULL)
            *rz = (*rz)->esq;
        else
            *rz = NULL;
        return aux;
    }
}

void removerRec(NO **raiz, int elemento){
    NO *aux;
    if(arvoreVazia(raiz)){
        printf("Arvore vazia!!\n");
        return;
    }
    if(elemento < (*raiz)->info){
        removerRec(&(*raiz)->esq, elemento);
    }else if(elemento > (*raiz)->info){
        removerRec(&(*raiz)->dir, elemento);
    }else{
        aux= *raiz;

        if(((*raiz)->esq == NULL) && ((*raiz)->dir == NULL)){
            free(aux);
            (*raiz) = NULL;
        }else{
            if((*raiz)->esq == NULL){
                (*raiz) = (*raiz)->dir;
                aux->dir = NULL;
                free(aux);
            }else{
                if((*raiz)->dir == NULL){
                    (*raiz) = (*raiz)->esq;
                    aux->esq = NULL;
                    free(aux);
                }else{
                    aux = maiorElemento(&(*raiz)->esq);
                    aux->esq = (*raiz)->esq;
                    aux->dir = (*raiz)->dir;
                    free(*raiz);
                    *raiz = aux;
                }
            }
        }
    }
    return;
}

NO *removerNo(NO *no){
    NO *no1, *no2;

    if(no->esq == NULL){
        no2= no->dir;
        free(no);
        return no2;
    }

    no1 = no;
    no2 = no->esq;

    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != no){
        no1->dir = no2->esq;
        no2->esq = no->esq;
    }

    no2->dir = no->dir;
    free(no);
    return no2;
}

int removerNoB(NO **raiz, int elemento){
    NO *aux = (*raiz), *prev = NULL;

    if(arvoreVazia(raiz))
        return 0;

    while(aux != NULL){
        if(elemento == aux->info){
            if(aux== (*raiz))
                (*raiz) == removerNo(aux);
            else{
                if(prev->dir == aux)
                    prev->dir = removerNo(aux);
                else
                    prev->esq = removerNo(aux);
            }
            return 1;
        }
        prev= aux;
        if(elemento > aux->info)
            aux = aux->dir;
        else
            aux = aux->esq;
    }
    return 1;
}


int main(){

    NO *raiz, *elemento;
    raiz = NULL;

    inserirRecursivo(&raiz, 7);
    elemento= pesquisar(raiz, 7);
    printf("elemento = %d\n", elemento->info);
    inserirRecursivo(&raiz, 10);
    elemento = pesquisar(raiz, 10);
    printf("elemento = %d\n", elemento->info);

    if(removerNoB(&raiz, 7))
        printf("Elemento removido com sucesso!\n");
    return 0;
}


