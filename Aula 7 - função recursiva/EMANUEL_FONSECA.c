#include<stdio.h>
#include<string.h>

//Emanuel Fonseca -- CJ3005925

char vetor[]="Palavra Invertida";
int vet[20];

int imprimirDecrecente(int i){
    int res;
    printf("%d", i);
    if(i==1)
        return main();
    return  imprimirDecrecente(i-1);
}
int imprimirCrescente(int i){
    printf("%d", i);
    if(i==5)
        return main();
    return imprimirCrescente(i+1);
}
char palavraDecre(int quant){
    printf("%c", vetor[quant]);
    if(quant==0)
        return main();
    return palavraDecre(quant-1);
}
int somatorioNumeros(int soma,int numeroInicial, int numeroFinal){
    soma=soma+numeroFinal;
    if(numeroFinal==numeroInicial){
        return soma;
    }
    return somatorioNumeros(soma ,numeroInicial, numeroFinal-1);
}
int comparacaoChave(int chave, int i2){
    if(vet[i2]==chave)
        return 1;
    if(i2==21)
        return 0;
    return comparacaoChave(chave,i2+1);
}
int main(){
    int opcao, opcao2;
    int n=5,n2=1;
    int quant,soma;
    int numeroInicial, numeroFinal;
    int chave, i2=0, r=0;

    do{
        printf("\n================================================================\n[1]- Exercicio 1\n[2]- Exercicio 2\n[3]- Exercicio 3\n[4]- Exercicio 4\n================================================================\n");
        scanf("%d", &opcao);
    }while(opcao<1 || opcao>4);
        switch(opcao){
            case 1:
                printf("[1]- Ordem Decrescente\n");
                printf("[2]- Ordem Crescente\n");
                scanf("%d", &opcao2);
                switch(opcao2){
                    case 1:
                        imprimirDecrecente(n);
                        break;
                    case 2:
                        imprimirCrescente(n2);
                        break;
                    default:
                        printf("Opcao Invalida!! Voltando para o menu");
                        return main();
                }
                break;
            case 2:
                quant = strlen(vetor);
                palavraDecre(quant);
                break;
            case 3:

                printf("Numero Inicial: ");
                scanf("%d", &numeroInicial);
                printf("Numero Final: ");
                scanf("%d", &numeroFinal);
                soma=somatorioNumeros(soma ,numeroInicial, numeroFinal);
                printf("Soma entre os numero entre %d e %d eh: %d", numeroInicial,numeroFinal,soma);
                break;
            case 4:
                srand( time(NULL) );
                printf("Digite a chave: ");
                scanf("%d", &chave);
                for(int i=0;i<=20;i++){
                    vet[i]= rand()%10;
                    printf("%d  ", vet[i]);
                }
                r=comparacaoChave(chave,i2);
                if(r==1)
                    printf("\n\nChave Encontrada!!\n");
                else
                    printf("\n\nChave nao encontrada!!");
                break;
        }
        return main();
}
