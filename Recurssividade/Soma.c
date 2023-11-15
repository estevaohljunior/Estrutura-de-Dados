//Escreva um programa com uma função que some os N primeiros números inteiros. Ex: N=5, Resultado = 1+2+3+4+5=15

#include <stdio.h>
#include <stdlib.h>

int soma(int num) {
   if (num == 0){
        return 0;
    }else if(num < 0){
        printf("Erro");
        exit(1);
    }

    return (num + soma(num-1));
}

int main() {
    int num;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    int x = soma(num);
    printf("A soma dos %d primeiros numeros inteiros eh: %d\n", num, x);

    return 0;
}
