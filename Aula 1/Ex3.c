#include<stdio.h>

int main(){

    int valor;
    printf("Numero: ");
    scanf("%d", &valor);

    while(valor!=0){
        for(int i=1;i<=valor;i++){
            printf("*");
        }
        printf("\n");
        valor--;
    }
    return 0;
}
