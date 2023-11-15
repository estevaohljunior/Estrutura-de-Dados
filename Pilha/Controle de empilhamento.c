//Crie um programa que controla um empilhamento de caixas em um supermercado.
//Cada caixa tem algumas informações importantes: número de série, descrição do produto e fornecedor. 
//Defina o número máximo de caixas para o empilhamento. O programa tem três funções básicas: empilhar, desempilhar e mostrar conteúdo da pilha.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 10

void empilhar();
void desempilhar();
void imprimir_pilha();

struct caixa{
    int num_serie;
    char des[100];
    char fornecedor[100];
};
struct pilha{
    struct caixa caixas[tamanho];
    int topo;  
};
struct pilha p;

int main(){
    int op;
    p.topo = -1;

    do
    {
        printf("\n1 - Para empilhar\n2 - Para desempilhar\n3 - Para mostrar pilha\n4 - Para encerrar progrma!\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
           empilhar();
           break;
        case 2:
           desempilhar();
           break;
        case 3:
           imprimir_pilha();
           break;
        case 4:
           printf("\nPrograma Encerrado!!");
           break;
        default:
           printf("\nValor invalido!");
           break;
        }
    } while (op != 4);
    return 0;
}

void empilhar(){
    if(p.topo == tamanho-1){
        printf("\nA pilha ta cheia!!\n");
        system("pause");
    }else{
        struct caixa caixa_nova;
        printf("\nInforme o numero de serie: ");
        scanf("%d", &caixa_nova.num_serie);
        printf("\nInforme a descricao da caixa: ");
        scanf(" %[^\n]", caixa_nova.des);
        printf("\nInforme o fornecedor da caixa: ");
        scanf(" %[^\n]", caixa_nova.fornecedor);
        p.topo++;
        p.caixas[p.topo] = caixa_nova;
        printf("\nCaixa empilhada com sucesso!\n");
    }
}

void desempilhar(){
    if(p.topo == -1){
        printf("\nA caixa ta vazia!\n");
        system("pause");
    }else{
        struct caixa caixa_desempilha = p.caixas[p.topo];
        p.topo--;
        printf("Caixa desempilhada:\n");
        printf("Numero de serie: %d\n", caixa_desempilha.num_serie);
        printf("Descricao: %s\n", caixa_desempilha.des);
        printf("Fornecedor: %s\n", caixa_desempilha.fornecedor);
    }
}

void imprimir_pilha(){
    if(p.topo == -1){
        printf("\nA caixa ta vazia!\n");
        system("pause");      
    }else{
        for(int i = p.topo; i >= 0; i--){
            printf("\nCaixa %d: \n", i+1);
            printf("Numero de serie: %d\n", p.caixas[i].num_serie);
            printf("Descricao da caixa: %s\n", p.caixas[i].des);
            printf("Forcedor da caixa: %s\n", p.caixas[i].fornecedor);
        }
    }
}
