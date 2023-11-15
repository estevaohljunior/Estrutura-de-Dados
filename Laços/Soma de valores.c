//Construa um programa que imprime a soma de todos os valores positivos digitados pelo usuário até que ele digite um número negativo.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int soma = 0;
    int i = 1;
    int x;

    do
    {
        printf("\nDigite o %d numero: ", i);
        scanf("%d", &x);
        i++;

        if (x > 0){
            soma += x;
        }
        else {
            printf("\nValor negativo encontrado!");
        }
    } while (x > 0);
    printf("\nA soma: %d", soma);
   
    return 0;
}
