//Escreva um programa que imprime os números pares de 1 a 100.

#include <stdio.h>
#include <stdlib.h>

int main(){
   
    for(int i = 0; i < 100; i++){
        if (i % 2 == 0){
            printf("%d ", i);
        }
    }

    return 0;
}
