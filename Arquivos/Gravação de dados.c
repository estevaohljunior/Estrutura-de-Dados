//Construa um programa que permita ao usuário gravar 10 palavras em um arquivo e, em seguida, efetue a leitura do arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   FILE *arq;
   char palavra[100];
   char a_str[100];

   arq = fopen("Aquirvo.txt", "a");

   if(arq == NULL){
       printf("Erro");
       return 1;
   }
  
   for (int i = 0; i < 10; i++){
       printf("Digite a %d palavra: ", i+1);
       scanf("%s", palavra);
       fprintf(arq, "\n%s", palavra);
   }
   fclose(arq);

   arq = fopen("Aquirvo.txt", "r");
   if(arq == NULL){
       printf("Erro");
       return 1;
   }

   printf("\nImprimindo as palavras digitadas!\n");

   while(fgets(a_str, 100, arq) != NULL){
       printf("%s", a_str);
   }

   return 0;
}
