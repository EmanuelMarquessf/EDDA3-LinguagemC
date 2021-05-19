#include<stdio.h>

// Emanuel Fonseca - CJ3005925

int main(){
    int menu;
        printf("\n===============================\n1- Exercicio 1\n2- Exercicio 2\n3- Exercicio 3\n4- Sair\n===============================\n");
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
            printf("Opcao Invalida!!");
            return main();
        }
        return 0;
    }

void Ex1(){
int valor, opcao, i=0, fatorial=1;

    printf("Digite um numero: ");
    scanf("%d", &valor);

    printf("\n===============================\n1- For\n2- While\n3- Do While\n===============================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");
    switch (opcao){
    case 1:
        for(int i=0 ; i < valor-1 ; i++){
            fatorial =fatorial*(valor-i);
        }
        printf("%d!: %d\n",valor, fatorial);
        break;
    case 2:
        while(i<valor-1){
            fatorial =fatorial*(valor-i);
            i++;
        }
        printf("%d!: %d\n",valor, fatorial);
        break;
    case 3:
        do{
            fatorial =fatorial*(valor-i);
            i++;
        }while(i<valor-1);
        printf("%d!: %d\n",valor, fatorial);
        break;
    default:
        printf("Opcao Invalida!!");
    }
    return main();
}

void Ex2(){
    int quantidade, quantDiv, numeroAtual=1, divisor=2;
    printf("Digite o numero de numeros primos desejados: ");
    scanf("%d", &quantidade);
    printf("\n");

    while(numeroAtual<=quantidade){
        for(int i=2; i<=divisor; i++){
            if(divisor % i==0){
                quantDiv++;
            }
        }
        if(quantDiv==1){
            printf("%d\n",divisor);
            numeroAtual++;
        }
        divisor++;
        quantDiv=0;
    }
    return main();
}
void Ex3(){
    int valor;
    printf("Tamanho da arvore: ");
    scanf("%d", &valor);

    while(valor!=0){
        for(int i=1;i<=valor;i++){
            printf("*");
        }
        printf("\n");
        valor--;
    }
    return main();
}
