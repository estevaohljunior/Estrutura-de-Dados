#include <stdio.h>
#include <stdlib.h>
#include "avaliacao3.h"


int main(void) {
  TPilhaEnc p1=NULL, p_clone=NULL, p3=NULL, p4;
  int op;

  criarPilha(&p1);
  criarPilha(&p_clone);

  //While que serve para criar interação entre usuário e programa
  while (1){
    int op=0, elemento=0;
    printf("Escolha uma opção(número) para ser executada: \n0 - Encerrar programa.\n1 - Inserir elementos na pilha 1.\n2 - Realizar clonagem da pilha.\n");
    scanf("%d", &op);
    //escolher 0 encerra o programa
    if (op==0) break;

    //escolher 1 permite o empilhamento de um elemento a ser digitado pelo usuário
    else if (op==1) {
      printf("Digite o elemento a ser empilhado: ");
      scanf("%d", &elemento);
      
      //se por algum acaso o SO não for capaz de empilhar o elemento o programa exibe mensagem de falha, caso contrario uma mensagem de sucesso ao empilhar
      if (empilhar(&p1, elemento)) printf("Elemento empilhado com sucesso!\n\n");

      else printf("Falha ao empilhar elemento.\n");

      //por fim a lista é imprimida pra se ter um acompanhamento dos seus elementos internos
      imprimir(p1);
    }

    //escolhendo a opção 2 é criada uma pilha clone da pilha 1. e em seguida ela é imprimida para se ter um acompanhamento da clonagem
    else if (op==2) {
      //caso a função clonar retorne 0 ou o tamanho da pilha 1 for 0, o programa exibe uma mensagem de falha, caso contrario a clonagem é feita com sucesso e as duas pilhas são imprimidas
      if ( (clonar(&p1, &p_clone)==0) | (tamanhoPilha(p1)!=0) ){
        printf("Pilha clonada com sucesso!\n\n");
        imprimir(p1);
        printf("(Clone) ");
        imprimir(p_clone);
      }
      
      else printf("Falha ao clonar pilha.\n");

    }
    //mensagem em caso de escolha de opão errada
    else printf("\nINSIRA UMA OPÇÂO VÁLIDA, POR FAVOR!!!\n\n");
  }

  //aqui a memória alocada é liberada
  free(p1);
  free(p_clone);
}

/* Criar uma pilha vazia */
void criarPilha( TPilhaEnc *pilha ){
	*pilha = NULL;
}

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilhaEnc pilha ){
	return pilha == NULL;
}

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha ){
	int tamanho = 0;
	while( pilha != NULL ) {
		pilha = pilha->prox;
		tamanho++;
	}
	return tamanho;
}

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado ){
	TPilhaEnc novo;

	// aloca o no e testa pra ver se o SO alocou mesmo
	if( (novo = (no*) malloc(sizeof(no))) == NULL ) return 0;

	novo->dado = dado;
	novo->prox = *pilha;
	*pilha = novo;
	return 1;
}

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado ){
	// se pilha está vazia
   	if ( pilhaVazia( *pilha ) ) return 0;

	TPilhaEnc aux;

	aux = *pilha;
	*dado = aux->dado;
	*pilha = (*pilha)->prox;
	
	// libera memória do nó desempilhado
	free( aux );

    return 1;
}


/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado ){
	if( pilhaVazia( pilha ) ) return 0;

	*dado = pilha->dado; // já que topo é igual ao primeiro no
	return 1;
}

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha ){
	// se pilha está vazia
   	if ( pilhaVazia( pilha ) ) return 0;

    printf("Pilha=[ ");

	// varrendo todos os elementos
	while( !pilhaVazia(pilha) ){
		printf("%d ", pilha->dado);
		pilha = pilha->prox;
	}

    printf("]\n\n");
     return 1;
}

int clonar (TPilhaEnc *origem, TPilhaEnc *destino){
  TPilhaEnc auxRes=NULL, aux1=NULL;
  int t_p1=0;
  // as duas variáveis auxiliares do tipo TPilhaEnc recebem o endereço do primeiro nó da origem, porém a variável aux1 será modificada no decorrer do programa
  auxRes = *origem;
  aux1=*origem;

  // aloca o no e testa pra ver se o SO alocou mesmo
  if( (auxRes = aloca()) == NULL ) return 0;
  
  //essa variável recebe o tamanho da pilha de origem
  t_p1 = tamanhoPilha(*origem);

  //aqui é definida uma lista que irá receber os elementos da pilha 1, iniciando do topo até a base, já a variável contador é somente uma variável de controle de loop
  int l_el[t_p1], contador=0;

  //este while é responsável por percorrer a pilha de origem a partir da variável aux1, os dados da pilha de origem são aramazenados na lista l_el, a pilha passa para o próximo nó e o contador coma 1 ao seu valor para que no próximo ciclo o elemento em aux1->dado seja inserido num novo indice na lista
  while( !pilhaVazia(aux1) ){
		l_el[contador] = aux1->dado;
		aux1 = aux1->prox;
    contador++;
	}
  
  //por fim, esse for percorre a lista de trás pra frente e empilha o elemento da lista no topo da pilha com a função empilhar
  for (int i=0; i<contador; i++){
    empilhar(destino,l_el[contador-i-1]);
  }
  return 0;
}

//sub-rotina de alocação dinamica
TPilhaEnc aloca(){
  return (no*) malloc(sizeof(no));
}

