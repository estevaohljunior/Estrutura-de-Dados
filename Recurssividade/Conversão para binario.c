//Escreva um programa com uma função que converta um número inteiro decimal para sua forma binária.

#include <stdio.h>
#include <stdlib.h>

int binario(int num){
    if (num == 0){
        return (0);
    } else {
        binario(num / 2);
        printf("%d", num%2);
    }
}

int main() {
    int num;

    printf("Digite um numero maior que zero: ");
    scanf("%d", &num);
    
    printf("O valor %d convertido para binario eh: ", num);
    binario(num);

    return 0;
}
