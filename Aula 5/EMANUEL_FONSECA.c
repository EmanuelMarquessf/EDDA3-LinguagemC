#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Emanuel Fonseca - CJ3005925

float distancia(float x1, float y1, float x2, float y2){
    float d;
    d=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return d;
}
int fatorial(int num){
    int fat=1;
    for(int i=0 ; i < num-1 ; i++)
        fat =fat*(num-i);
    return fat;
}
int somatorio(int num){
    int som=1;
    for(int i=0 ; i < num-1 ; i++)
        som =som+(num-i);
    return som;
}
int somAlgorismos(int num){
    int centenas=0, desenas=0, soma;
    if(num > 99 && num<1000){
        centenas=num/100;
        num-=(centenas*100);
    }
    if(num>9 && num<100){
       desenas=num/10;
       num-=(desenas*10);
    }
    soma=centenas+desenas+num;
    printf("%d + %d + %d =", centenas, desenas, num);
    return soma;
}

int main(){
    int opcao;
    float x1,y1,x2,y2;
    int num=0;
    do{
        printf("\n================================================================\n[1]- Exercicio 1 - Distancia entre 2 pontos no Plano Cartesiano\n[2]- Exercicio 2 - Fatorial\n[3]- Exercicio 3 - Soma \n[4]- Exercicio 4 - Soma Algarismos\n================================================================\n");
        scanf("%d", &opcao);
    }while(opcao<1 || opcao>4);
        switch(opcao){
            case 1:
                printf("P1(X1,): ");
                scanf("%f", &x1);
                printf("P1(,Y1) : ");
                scanf("%f", &y1);
                printf("\nP2(X2,): ");
                scanf("%f", &x2);
                printf("P2(,Y2) : ");
                scanf("%f", &y2);
                printf("\nP1(%.2f,%.2f)\tP2(%.2f,%.2f)\n", x1,y1,x2,y2);
                printf("Distancia:\t%f", distancia(x1,y1,x2,y2));
                break;
            case 2:
                printf("Numero: ");
                scanf("%d" ,&num);
                printf("%d!= %d",num,fatorial(num));
                break;
            case 3:
                printf("Numero: ");
                scanf("%d" ,&num);
                printf("%d+= %d",num,somatorio(num));
                break;
            case 4:
                do{
                    printf("Numero: ");
                    scanf("%d" ,&num);
                }while(num<1 || num>999);
                printf(" %d\n", somAlgorismos(num));

                break;
            default:
                printf("Valor Invalido!!!");
                break;
        }
        return main();
}











