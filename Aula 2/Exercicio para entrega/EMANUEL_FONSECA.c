#include<stdio.h>

// Emanuel Fonseca - CJ3005925

int main(){
    int menu, opcao;
    do{
        printf("\n===============================\nExercicios Aula:\n\n1- Exercicio 1\n2- Exercicio 2\n3- Exercicio 3\n\nExercicios Tarefa:\n\n4- Exercicio 4\n5- Exercicio 5\n6- Exercicio 6\n\n7- Sair\n===============================\n");
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
            system("cls");
            Ex4();
            break;
        case 5:
            system("cls");
            Ex5();
            break;
        case 6:
            system("cls");
            Ex6();
            break;
        case 7:
            system("taskkill /IM cb_console_runner.exe");
            break;
        default:
            system("cls");
            printf("Opcao Invalida!!");
            opcao=0;
    }}
    while(opcao==0);
    return 0;
}
void Ex1(){
    float nota;
    do{
        printf("Digite uma nota: ");
        scanf("%f", &nota);
    }while(nota < 0 || nota > 100);
    if(nota==0){
        printf("Nota: E");
    }
    else if(nota>=1 && nota<=35){
        printf("Nota: D");
    }
    else if(nota>=35 && nota<=60){
        printf("Nota: C");
    }
    else if(nota>=61 && nota<=85){
        printf("Nota: B");
    }
    else{
        printf("Nota: A");
    }
    return 0;
}
void Ex2(){
    int numero,soma=0;
    do{
        printf("Digite o numero: ");
        scanf("%d", &numero);
        soma+=numero;
    }while(numero!=0);
    printf("%d", soma);
return 0;
}
void Ex3(){
    srand( time(NULL) );
    int segredo=rand(), valor;

    do{
        printf("Digite seu numero: ");
        scanf("%d", &valor);
        if(valor>segredo){
            printf("%d e Maior\n", valor);
        }
        else if(valor<segredo && valor>0){
            printf("%d e Menor\n", valor);
        }
        else if(valor==segredo){
            printf("%d e Igual\n", valor);
        }
        else if(valor==0){
            printf("Desistiu!!");
            break;
        }
    }while(valor!=segredo);

return 0;
}
void Ex4(){
     long int M, N, soma1, soma2,sf,opcao=1,op=1;
     while(op==1){
        do{
            soma1=1;
            soma2=1;
            printf("Exercicio soma de fatoriais\nDigite o 1 valor: ");
            scanf("%d", &M);
            printf("\nDigite o 2 valor: ");
            scanf("%d", &N);
            if(M<0 || M>20 || N<0 || N>20){
                printf("\nPor favor, digite numeros entre 0 e 20\n\n");
                opcao=0;
            }
            else
                opcao=1;
        }while(opcao==0);
        for(int i=0 ; i < M-1 ; i++){
            soma1 =soma1*(M-i);
        }
        for(int i=0 ; i < N-1 ; i++){
            soma2 =soma2*(N-i);
        }
        sf=soma1+soma2;
        printf("%d! + %d! = %d\n", M, N, sf);
     }
    return 0;
}

void Ex5(){
    int quantTestes;
    float quantComida;
    int dias=0, opcao;
    do{
        printf("Quantidade de testes: ");
        scanf("%d", &quantTestes);
        if(quantTestes <= 0 || quantTestes>=1000){
            printf("\nPor favor, digite numeros entre 1 e 1000\n\n");
        }
    }while(quantTestes <= 0 || quantTestes>=1000);
    for(int i=0;i < quantTestes;i++){
        do{
            dias=0;
            printf("Quantidade de comida(KG): ");
            scanf("%f", &quantComida);
            if(quantComida<=1 || quantComida >=1000){
                printf("\nPor favor, digite numeros entre 1 e 1000\n\n");
                opcao=0;
            }
            else
                opcao=1;
        }while(opcao==0);
        while(quantComida>1){
            quantComida= quantComida*0.5;
            dias++;
        }
        printf("%d Dias\n", dias);
    }
    return 0;
}
void Ex6(){
    int valor1=1, v1100000000, v1010000000, v1001000000, v1000100000, v1000010000, v1000001000,v1000000100, v1000000010,v1000000001;
    int valor2=1, v2100000000, v2010000000, v2001000000, v2000100000, v2000010000, v2000001000,v2000000100, v2000000010,v2000000001;
    int carry=0;
    while(valor1!=0 && valor2!=0){
        carry=0;

        do{
            printf("2 Valores: ");
            scanf("%d %d", &valor1, &valor2);
            if(valor1<0 || valor1>999999999 || valor2<0 || valor2>999999999){
                printf("Por favor, digite numeros entre 1 e 999999999\n\n");
            }
        }while(valor1<0 || valor1>999999999 || valor2<0 || valor2>999999999);

        if(valor1>=100000000){
            v1100000000=valor1/100000000;
            valor1-=(v1100000000*100000000);
        }
        else
            v1100000000=0;
        if(valor1<=999999999 && valor1>=10000000){
            v1010000000=(valor1/10000000);
            valor1-=(v1010000000*10000000);
        }
        else
            v1010000000=0;
        if(valor1<=99999999 && valor1>=1000000){
            v1001000000=(valor1/1000000);
            valor1-=(v1001000000*1000000);
        }
        else
            v1001000000=0;
        if(valor1<=9999999 && valor1>=100000){
            v1000100000=(valor1/100000);
            valor1-=(v1000100000*100000);
        }
        else
            v1000100000=0;
        if(valor1<=999999 && valor1>=10000){
            v1000010000=(valor1/10000);
            valor1-=(v1000010000*10000);
        }
        else
            v1000010000=0;
        if(valor1<=99999 && valor1>=1000){
            v1000001000=(valor1/1000);
            valor1-=(v1000001000*1000);
        }
        else
            v1000001000=0;
        if(valor1<=9999 && valor1>=100){
            v1000000100=(valor1/100);
            valor1-=(v1000000100*100);
        }
        else
            v1000000100=0;
        if(valor1<=999 && valor1>=10){
            v1000000010=(valor1/10);
            valor1-=(v1000000010*10);
        }
        else
            v1000000010=0;
        if(valor1<=99 && valor1>=1){
            v1000000001=(valor1/1);
            valor1=v1000000001;
        }
        else
            v1000000001=0;

        if(valor2>=100000000){
            v2100000000=valor2/100000000;
            valor2-=(0*100000000);
        }
        else
            v2100000000=0;
        if(valor2<=999999999 && valor2>=10000000){
            v2010000000=(valor2/10000000);
            valor2-=(v2010000000*10000000);
        }
        else
            v2010000000=0;
        if(valor2<=99999999 && valor2>=1000000){
            v2001000000=(valor2/1000000);
            valor2-=(v2001000000*1000000);
        }
        else
            v2001000000=0;
        if(valor2<=9999999 && valor2>=100000){
            v2000100000=(valor2/100000);
            valor2-=(v2000100000*100000);
        }
        else
            v2000100000=0;
        if(valor2<=999999 && valor2>=10000){
            v2000010000=(valor2/10000);
            valor2-=(v2000010000*10000);
        }
        else
            v2000010000=0;
        if(valor2<=99999 && valor2>=1000){
            v2000001000=(valor2/1000);
            valor2-=(v2000001000*1000);
        }
        else
            v2000001000=0;
        if(valor2<=9999 && valor2>=100){
            v2000000100=(valor2/100);
            valor2-=(v2000000100*100);
        }
        else
            v2000000100=0;
        if(valor2<=999 && valor2>=10){
            v2000000010=(valor2/10);
            valor2-=(v2000000010*10);
        }
        else
            v2000000010=0;
        if(valor2<=99 && valor2>=1){
            v2000000001=(valor2/1);
            valor2=v2000000001*1;
        }
        else
            v2000000001=0;
        if((v1100000000+v2100000000)>9)
            carry++;
        if((v1010000000+v2010000000)>9)
            carry++;
        if((v1001000000+v2001000000)>9)
            carry++;
        if((v1000100000+v2000100000)>9)
            carry++;
        if((v1000010000+v2000010000)>9)
            carry++;
        if((v1000001000+v2000001000)>9)
            carry++;
        if((v1000000100+v2000000100)>9)
            carry++;
        if((v1000000010+v2000000010)>9)
            carry++;
        if((v1000000001+v2000000001)>9)
            carry++;


            printf("%d Operacao/s leva 1\n\n", carry);

    }
    return 0;
}


