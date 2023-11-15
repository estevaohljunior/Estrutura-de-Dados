//Utilizando alocação dinâmica de memória, escreva um programa que receba um vetor de n inteiros (até que digite 0 - sair)
//E os endereços de duas variáveis inteiras, digamos min e max, e deposite nessas variáveis o menor valor digitado e o maior.
//Ex: 1 20 30 50
//min = 1 e max = 50

#include <stdio.h>
#include <stdlib.h>

void maior_menor(int *vetor, int tam, int *min, int *max);

int main(){
 int num, min, max;
 int *vetor;
 int i = 0, j = 0;

 vetor = (int*)malloc(sizeof(int));

 do
 {
   j++;
   printf("\nDigite o %d valor: ", j);
   scanf("%d", &num);

   if(num != 0){
     vetor[i] = num;
     i++;
     vetor = (int*)realloc(vetor,(i+1) * sizeof(int));
   }
 } while (num != 0);

 maior_menor(vetor, i ,&min, &max);
 printf("\nO maior valor digitado: %d\nO menor valor digitado: %d\n", max, min);
 free(vetor);
 return 0;
}

void maior_menor(int *vetor, int tam, int *min, int *max){
 *max = vetor[0];
 *min = vetor[0];

 for(int i = 0; i < tam; i++){
   if(vetor[i] > *max){
     *max = vetor[i];
   }
   if(vetor[i] < *min){
     *min = vetor[i];
   }
 }
}
