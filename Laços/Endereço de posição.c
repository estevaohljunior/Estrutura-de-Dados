//Crie um programa que contenha um vetor contendo 5 elementos inteiros. Leia esse vetor do teclado e imprima o endereço das posições contendo valores pares.

#include <stdio.h>
#include <stdlib.h>

int main(){
 int tam = 5;
 int vetor[tam];

 for(int i = 0; i < tam; i++){
   printf("\nInforme o %d valor: ", i+1);
   scanf("%d", &vetor[i]);
 }
  
 printf("\n");
  
 for(int i = 0; i < tam; i++){
   if(vetor[i] % 2 == 0){
     printf("Valor par %d, posicao na memoria %p\n", vetor[i], &vetor[i]);
   }
 }
  
 return 0;
}
