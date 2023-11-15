//Utilize o comando de seleção múltiplo e faça um programa que informe a quantidade total de calorias a partir da escolha do usuário que deve informar o prato típico e a bebida. 
//A Tabela de calorias encontra-se abaixo:

//    Prato            |           Bebida
//Italiano 750cal      |        Chá 30 cal
//Japonês 342cal       |     Suco de laranja 80 cal
//Salvadoreno 545cal   |   Refrigerante 90 cal

#include <stdio.h>

int main() {
 int op, bebida;

 printf("Informe o prato que deseja: \n1 - Para Italiano: \n2 - Para Japones: \n3 - Para Salvadoreno: \n");
 scanf("%d", &op);
  printf("\nInforme a bebida que deseja: \n1 - Para Cha: \n2 - Para Suco de laranja: \n3 - Para Refrigerante: \n");
 scanf("%d", &bebida);

 switch(op) {
   case 1:
     printf("\nO prato Italiano tem 750 cal!");
     break;
   case 2:
     printf("\nO prato japones tem 342 cal!");
     break;
   case 3:
     printf("\nO prato Salvadoreno tem 545 cal!");
     break;
   default:
     printf("\nOperador invalido");
     break;
 }

   switch(bebida) {
   case 1:
     printf("\nO Cha tem 30 cal!");
     break;
   case 2:
     printf("\nO Suco de Laranja tem 80 cal!");
     break;
   case 3:
     printf("\nO refrigerante tem 90 cal!");
     break;
   default:
     printf("\nOperador invalido");
     break;
 }
  return 0;
}
