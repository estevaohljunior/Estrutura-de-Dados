//Crie um programa que controle a fila escolar na hora da merenda.
//Para evitar que os alunos se aglomerem, a escola optou em criar um sistema em que os alunos retiram fichas, e com base no número da ficha, o aluno é chamado para pegar sua merenda. 
//O programa recolhe algumas informações importantes como matrícula, nome e ano escolar da criança. 
//Esta escola tem cerca de 100 alunos matriculados, porém a cada dia é feito uma contagem de alunos para que as cozinheiras preparem a quantidade de alimentos necessários. 
//Então, solicite ao usuário que informe o número máximo de alunos que irão lanchar no dia. O programa tem três funções básicas: enfileirar, desenfileirar e mostrar conteúdo da fila.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 100

void enfileirar();
void desenfileirar();
void imprimir();

struct tdados{
    int matricula;
    int ano_escolar;
    char nome[50];
};
struct tfila{
    struct tdados dados[tamanho];
    int ini_aluno;
    int fim_aluno;
};
struct tfila fila;

int main(){
    fila.ini_aluno = 0;
    fila.fim_aluno = 0;
    int op, tam;
    printf("\nInforme quantos alunos irao lanchar: ");
    scanf("%d", &tam);
  
    do{
        printf("\n==========MENU DA FILA==========\n");
        printf("1 - Para enfileirar\n2 - Para desenfileirar\n3 - Para imprimir fila\n4 - Para encerrar programa\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            enfileirar(tam);
            break;
        case 2:
            desenfileirar(tam);
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nPROGRAMA ENCERRADO.");
            break;
        default:
            printf("\nValor invalido!");
            break;
        }
    }while(op != 4);
    return 0;
}

void enfileirar(tam){
    if(fila.fim_aluno == tam){
        printf("\nA fila ta cheia!\n");
        system("pause");
    }else{
        printf("\nInforme a Matricula: ");
        scanf("%d", &fila.dados[fila.fim_aluno].matricula);
        printf("\nInforme o Nome: ");
        scanf(" %[^\n]", &fila.dados[fila.fim_aluno].nome);
        printf("\nInforme o Ano Escolar: ");
        scanf("%d", &fila.dados[fila.fim_aluno].ano_escolar);
        fila.fim_aluno++;
    }
}

void desenfileirar(tam){
    if(fila.fim_aluno == fila.ini_aluno){
        printf("\nA fila está vazia!\n");
        system("pause");
    } else {
        for(int i = 0; i < tam - 1; i++){
            fila.dados[i] = fila.dados[i+1];
        }
        fila.fim_aluno--;
        printf("\nAluno removido da fila.\n");
    }
}

void imprimir(){
    if(fila.fim_aluno == fila.ini_aluno){
        printf("\nA fila ta vazia!\n");
        system("pause");
    }else{
        printf("\nFila de alunos:\n");
        for(int i = fila.ini_aluno; i < fila.fim_aluno; i++){
            printf("\nMatricula do %d aluno: %d", i+1,fila.dados[i].matricula);
            printf("\nNome: %s", fila.dados[i].nome);
            printf("\nAno escolar: %d\n", fila.dados[i].ano_escolar);
        }
    }
}
