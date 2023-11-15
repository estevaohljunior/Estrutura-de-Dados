//Escreva um programa que lê o nome de um aluno, o nome de uma disciplina e as notas de 4 provas realizadas nela. 
//Calcule e apresente na tela a média aritmética alcançada por essas notas.
//Imprima essa informação através de uma mensagem que informe também o nome do aluno e da disciplina cursada.

include <stdio.h>
#include <string.h>

int main()
{
    char nome[10];
    char dis[10];
   
    printf("\nDigite o nome do aluno: ");
    scanf("%s", &nome);
    printf("Digite o nome da disciplina: ");
    scanf("%s", &dis);
   
    float notas[4], m;
    int x = 0;
   
    for (int i = 0; i < 4; i++) {
        x = x + 1;
        printf("\nDigite a %d nota: ", x);
        scanf("%f", &notas[i]);
    }
   
    m = (notas[0] + notas[1] + notas[2] + notas[3]) / 4;
   
    printf("O aluno %s teve a media %.2f na diciplina %s", nome,m,dis);
   
    return 0;
}
