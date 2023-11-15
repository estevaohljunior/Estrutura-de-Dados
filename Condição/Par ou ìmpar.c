//Desenvolva um programa em C que recebe um número e informa se ele é par ou ímpar.
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    if (num % 2 == 0){
        printf("Numero par!");
    }
    else{
        printf("Numero impar!");
    }
    return 0;
}
