//Utilizando ponteiros, faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e troque o seu conteúdo.
//Esta função é chamada passando duas variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B terá o valor de A.

#include <stdio.h>
#include <stdlib.h>

void trocar(double *num, double *num2);

int main(){
 int x, y;

 printf("Digite um valor: ");
 scanf("%d", &x);
 printf("\nDigite outro valor: "); 
 scanf("%d", &y);

 double *yy = &y;
 double *xx = &x;
  printf("\nAntes da troca!\nX = %d\nY = %d\n", x, y);
 trocar(&x, &y);
 printf("\nDepois da troca!\nX = %d\nY = %d\n", x, y);
  
 return 0;
}
void trocar(double *num, double *num2){
 double aux = *num;
 *num = *num2;
 *num2 = aux;
}
