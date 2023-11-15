//Faça um programa que crie uma lista de contatos de 10 pessoas. 
//Os contatos devem ter nome, telefone, endereço, profissão, idade, sexo e data de nascimento. 
//Em seguida crie um menu com opções para gravar a lista em um arquivo e em seguida ler o arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_contatos = 0;
char nome[30];
char telefone[30];
char endereco[30];
char profissao[30];
char idade[30];
char sexo[30];
char data_nascimento[30];

void adicionar_contato() {
    if (num_contatos >= 10) {
        printf("Não é possível adicionar mais contatos.\n");
        return;
    }
    printf("Digite o nome: ");
    scanf("%s", &nome);

    printf("Digite o telefone: ");
    scanf("%s", &telefone);

    printf("Digite o endereco: ");
    scanf("%s", &endereco);

    printf("Digite a profissao: ");
    scanf("%s", &profissao);

    printf("Digite a idade: ");
    scanf("%s", &idade);

    printf("Digite o sexo: ");
    scanf("%s", &sexo);
   
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%s", &data_nascimento);
    num_contatos++;
}

int main(){
    FILE *arquivo;
    int op;
    char c;

    arquivo = fopen("dados.txt", "w");
    fprintf(arquivo, "Nome,Telefone,Endereco,Profissao,Idade,Sexo,Data de Nascimento\n");
    fclose(arquivo);
  
    do{
        printf("\n1 - Para guardar dados.\n2 - Para ler dados.\n3 - Para encerrar programa.\n");
        scanf("%d", &op);
        switch (op){
        case 1:
            adicionar_contato();
            arquivo = fopen("dados.txt", "a");
            if (arquivo == NULL) {
               printf("Erro ao abrir o arquivo.\n");
               return 1;
               }
            fprintf(arquivo, "\n%s, %s, %s, %s, %s, %s, %s", nome, telefone, endereco, profissao, idade, sexo, data_nascimento);
            fclose(arquivo);
            printf("Contatos salvos no arquivo com sucesso!\n");
            break;
        case 2:
            arquivo = fopen("dados.txt", "r");
            if(arquivo == NULL){
                printf("Erro!!");
                return 1;
            }
            do{
                c = fgetc(arquivo);
                printf("%c", c);
            } while (c != EOF);
            break;
        case 3:
            printf("\nPrograma Encerrado!");
            break;
        default:
            break;
        }
    }while(op != 3);
   
    return 0;
}
