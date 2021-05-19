#include<stdio.h>

int main(){

    char str[100];
    int a = 444;
int i;

sprintf(str,"%d",a);

for(i=0;i<strlen(str);++i)
 printf("%c ",str[i]);
}
