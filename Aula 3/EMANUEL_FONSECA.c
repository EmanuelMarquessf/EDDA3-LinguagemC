#include<stdio.h>

// Emanuel Fonseca - CJ3005925

int main(){
    int menu;
        printf("\n================================================\n1- Exercicio 1 - Coordenadas numero em matriz\n2- Exercicio 2 - Matriz Transposta\n3- Exercicio 3 - Soma Pares e Impares em matriz\n4- Sair\n================================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menu);

        switch(menu){
        case 1:
            system("cls");
            Ex1();
            break;
        case 2:
            system("cls");
            Ex2();
            break;
        case 3:
            system("cls");
            Ex3();
            break;
        case 4:
            system("taskkill /IM cb_console_runner.exe");
            break;
        default:
            printf("\nOpcao Invalida!!\n");
            return main();
        }
        return 0;
    }

void Ex1(){
    int vetor1[5][10];
    int numero;

    printf("Numero: ");
    scanf("%d", &numero);
    srand( time(NULL) );
    for(int i=0; i < 5; i++){
        for(int j=0; j < 10 ; j++){

            vetor1[i][j] = rand() % 10;
            printf("%d\t", vetor1[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i < 5; i++){
        for(int j=0; j < 10 ; j++){
            if(numero == vetor1[i][j])
                printf("\nValor encontrado em: [%d] [%d]\n", i, j);
        }
    }
    return main();
}

void Ex2(){
    int vetor1[10][10];

    srand( time(NULL) );
    for(int i=0; i < 10; i++){
        for(int j=0; j < 10 ; j++){
            vetor1[i][j] = rand() % 10;
            printf("%d\t", vetor1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n=========================== Matriz Transposta ===========================\n\n");

    for(int i=0; i < 10; i++){
        for(int j=0; j < 10 ; j++)
            printf("%d\t", vetor1[j][i]);
        printf("\n");
    }
    return main();
}
void Ex3(){
int vetor1[5][5], somaP=0, somaI=0;

    srand( time(NULL) );
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5 ; j++){
            vetor1[i][j] = rand() % 3;
            printf("%d\t", vetor1[i][j]);
            if(vetor1[i][j]%2==0)
                somaP+=vetor1[i][j];
            else
                somaI+=vetor1[i][j];
        }
        printf("\n");
    }
    printf("\nSoma pares: %d\n", somaP);
    printf("\nSoma Impares: %d\n", somaI);

    return main();
}
