#include<stdio.h>

int main(){
    int quantidade,numeroAtual=1,divisor=2,quantDiv;
    printf("Digite o numero de numeros primos desejados: ");
    scanf("%d", &quantidade);

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
    return 0;
}
