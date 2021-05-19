#include<stdio.h>

int main(){
    float nota;
    do{
        printf("Digite uma nota: ");
        scanf("%f", &nota);
    }while(nota < 0 || nota > 100);
    if(nota==0){
        printf("E");
    }
    else if(nota>=1 && nota<=35){
        printf("D");
    }
    else if(nota>=35 && nota<=60){
        printf("C");
    }
    else if(nota>=61 && nota<=85){
        printf("B");
    }
    else{
        printf("A");
    }

return 0;
}
