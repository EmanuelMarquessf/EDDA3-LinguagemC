#include<stdio.h>
#include<stdlib.h>

//Nome: Emanuel Fonseca
//Prontuário: CJ3005925

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

int Ex3(){
    CLIENTE x;
    CLIENTE *cli;
    int n;
    printf("\n=============================================\n");
    printf("Digite a quantidade de clientes: ");
    scanf("%d", &n);
    printf("\n=============================================\n");
    cli = (CLIENTE*) malloc(n * sizeof(CLIENTE));
    for(int i=0;i<n;i++){
        printf("Cliente %d: ", i+1);
        fflush(stdin);
        printf("Nome: ");
        scanf("%[^\n]", x.nome);
        printf("idade: ");
        scanf("%d", &x.idade);
        printf("Telefone: ");
        scanf("%d", &x.telefone);
        fflush(stdin);
        printf("Nome: %s\n", x.nome);
        printf("idade: %d\n", x.idade);
        printf("telefone: %d\n", x.telefone);
        printf("\n=============================================\n");
    }
    free(cli);
    return main();
}
int Ex4(){
    int **matriz, x, y;
    printf("Digite o tamanho X: ");
    scanf("%d", &x);
    printf("Digite o tamanho Y: ");
    scanf("%d", &y);

    matriz = (int **) malloc(x * y * sizeof(int *));

    for(int i=0 ; i<x ; i++){
        matriz=(int **) malloc(x*y*sizeof(int));
        for(int i2=0 ; i2<y ; i2++){
            matriz[i][i2]= rand()  % 10;
            printf("%d\t"), matriz[i][i2];
        }
        printf("\n");
    }
     for(int i=0 ; i<x ; i++){
        free(matriz[i]);
     }
    free(matriz);
    matriz= NULL;

    return main();
}

typedef struct carro{
char cor[20], modelo[20];
int preco;
}CARRO;

int cadastroCarro(CARRO *caCarro){
    printf("Modelo: ");
    fflush(stdin);
    scanf("%[^\n]", &caCarro->modelo);
    fflush(stdin);
    printf("Cor: ");
    scanf("%[^\n]", &caCarro -> cor);
    printf("Preco: ");
    scanf("%d", &caCarro ->preco);
    printf("Cadastro realizado com sucesso!!");
    free(caCarro);
}
int edicaoCarro(CARRO *ediCarro){
    printf("Modelo: ");
    fflush(stdin);
    scanf("%[^\n]", &ediCarro -> modelo);
    fflush(stdin);
    printf("Cor: ");
    scanf("%[^\n]", &ediCarro -> cor);
    printf("Preco: ");
    scanf("%d", &ediCarro -> preco);
    printf("Edição realizada com sucesso!!");
    free(ediCarro);
}

int Ex5(){
    CARRO *car;
    CARRO x;
    int opcao;

    printf("Modelo: ");
    fflush(stdin);
    scanf("%[^\n]", &x.modelo);
    fflush(stdin);
    printf("Cor: ");
    scanf("%[^\n]", &x.cor);
    printf("Preco: ");
    scanf("%d", &x.preco);

    do{
        printf("\n================================================================\n[1]- Cadastro\n[2]- Edicao\n================================================================\n");
        scanf("%d", &opcao);
    }while(opcao<1 || opcao>3);
        switch(opcao){
            case 1:
                cadastroCarro(&x);
                break;
            case 2:
                edicaoCarro(&x);
                break;
        }

}

int main(){
    int opcao;
    do{
        printf("\n================================================================\n[1]- Exercicio 1\n[2]- Exercicio 2\n[3]- Exercicio 3\n[4]- Exercicio 4\n[5]- Exercicio 5\n================================================================\n");
        scanf("%d", &opcao);
    }while(opcao<1 || opcao>5);
        switch(opcao){
            case 1:
                Ex1();
                break;
            case 2:
                Ex2();
                break;
            case 3:
                Ex3();
                break;
            case 4:
                Ex4();
                break;
            case 5:
                Ex5();
                break;
        }
        return main();
}
