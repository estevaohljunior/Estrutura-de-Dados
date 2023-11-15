//Escreva um programa que pede dois valores ao usuário e informa qual dos valores informados é maior.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, x;
    printf("Digite dois numero separados por espaco: ");
    scanf("%d %d", &num,&x);

    if (num > x){
        printf("O maior numero eh: %d", num);
    }
    else{
        printf("O maior numero eh: %d", x);
    }
    return 0;
}
