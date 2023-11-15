//Crie um programa para receber o comprimento de 3 pedaços de madeira e mostrar uma mensagem caso eles formem um triângulo. 
//Dica: monte uma expressão usando operadores lógicos e que seja verdadeira somente quando o comprimento de cada pedaço de madeira é menor que a soma do comprimento dos 2 pedaços restantes (A < B + C e B < A + C e C < A + B).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m[3];
    int x = 0;
   
    for (int i = 0; i < 3; i++) {
        x = x + 1;
        printf("Digite o comprimento do %d pedaco de madeira: ", x);
        scanf("%f", &m[i]);
    }
   
    if (m[0] + m[1] > m[2] && m[1] + m[2] > m[0] && m[0] + m[2] > m[1]) {
        printf("E um triangulo!");
    }else (printf("Nao e triangulo"));

    return 0;
}
