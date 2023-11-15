#include <stdio.h>
#include <stdlib.h>
#include "avaliacao_2.h"

int main(void){
  //Declaração de listas em TListaDupEnc
  TListaDupEnc l1=NULL, l2=NULL, l_merge=NULL;

  // Criação das listas
  criarLista(&l1);
  criarLista(&l2);
  criarLista(&l_merge);

  //inserção genérica dos elementos 
  for (int i=0; i<2; i++){
    if (i==0){
      inserir_fim(&l1,2.1);
      inserir_fim(&l1,4.5);
      inserir_fim(&l1,1.0);
      finaliza_insercao();
    }
    else {
      inserir_fim(&l2,7.2);
      inserir_fim(&l2,3.1);
      inserir_fim(&l2,9.8);      
      finaliza_insercao();
    }
  }
  // Chamando a função merge. para unir as listas l1 e l2
  l_merge=merge(&l1, &l2);
 
  // Imprimindo as listas l1 e l2 e o resultado da operação merge()
  imprimir(l1);
  imprimir(l2);
  imprimir(l_merge);
  
  // Desalocando a memória alocada dinamicamente
  free(l1);
  free(l2);
  free(l_merge);

  return 0;
  }

/**************************************************/

/* FUNÇÃO QUE CRIA A LISTA*/
void criarLista( TListaDupEnc *lista ){ 
  lista=NULL;
}

/* VERIFICA SE A LISTA ESTÁ VAZIA*/
int listaVazia( TListaDupEnc lista ){ 
  if (lista!=NULL) return 0;
    
  return 1; 
} 

/* REINICIALIZA A CONTAGEM DE N_ELEMENTOS PARA
PARA CRIAR E INSERIR EM OUTRA LISTA*/
void finaliza_insercao(){
  n_elementos=0;
}

/*SUB-ROTINA DE ALOCAÇÃO DINAMICA*/
TListaDupEnc aloca(){
  return (TListaDupEnc) malloc(sizeof(TListaDupEnc));
}

/* FUNÇÃO PARA INSERIR ELEMENTO AO FIM DA LISTA*/
int inserir_fim ( TListaDupEnc* lista, float dado ){
	TListaDupEnc novo = NULL, aux = NULL;
  int contador = 1;
  n_elementos++;
  // inserção em uma lista que está vazia
    if( listaVazia( *lista ) ) {
      // quando a lista está vazia, só é possível inserir na posição 1
	    // alocar o no e testar pra ver se tudo correu bem
      if( ( novo = aloca() ) == NULL ) return 0;
        novo->dado = dado;
        novo->prox = NULL;
        novo->ant = NULL;
        *lista = novo;

      return 1;
    }

  // inserção na ultima posição em uma lista não vazia
    aux = *lista;

	  // uma estratégia é fazer aux parar uma posição "antes" da real posição
	  while( ( contador < n_elementos -1 ) && ( aux != NULL ) ) {
  	  aux = aux->prox;
      contador++;
    }

    // alocar o novo nó
    if( ( novo = aloca() ) == NULL ) return 0;
  
    novo->dado = dado;
    novo->prox = aux->prox;
    novo->ant = aux;
    aux->prox = novo;

    return 1;
}

/*FUNÇÃO QUE CONTA O TAMANHO DA LISTA*/
int tamanhoLista( TListaDupEnc lista ){
	int tamanho = 0;
	while( lista != NULL ) {
    	lista = lista->prox;
        tamanho++;
    }
    return tamanho;
}

/*FUNÇÃO IMPRIMIR LISTA*/
  void imprimir ( TListaDupEnc lista ){
    //Se a lista conter elesmentos ela printa
    if ( !listaVazia(lista) ){
      printf("\nNúmero de elementos na lista: %d", tamanhoLista(lista));
      printf( "\nLista: (  ");

	  for( ;!listaVazia( lista ); lista = lista->prox )
	    printf("%.1f  ", lista->dado );

	  printf( ")\n" );
    }
    //se não, imprimi mensagem de lista vazia
    else printf("\nImpossível imprimir. LISTA VAZIA!\n");
}

TListaDupEnc merge(TListaDupEnc *lst1, TListaDupEnc *lst2){
  //declaração/atribuição das listas e auxiliares
  TListaDupEnc lstm=NULL, aux1=*lst1, aux2=*lst2;
  //criando lista a ser retornada após modificação
  criarLista(&lstm);

  /*para tornar possível a mescla alternada de listas de tamanhos 
  diversos, o while percorre as listas, adicionando e o dado atual
  e em seguida pulando para o próximo nó.
  */
  while ( !listaVazia(aux1) && !listaVazia(aux2) ){
    inserir_fim(&lstm, aux1->dado);
    inserir_fim(&lstm, aux2->dado);
    aux1=aux1->prox;
    aux2=aux2->prox;
  }

  /* se as listaas forem de tamanhos diferentes, o while acima vai  
  encerrar. Então vemos qual a lista que faltou inserir elemnetos com tamanho lista e continua a inserção dos elementos que faltaram, 
  com outro while
  */
  if ( tamanhoLista(aux1)>tamanhoLista(aux2) ) {
    while (!listaVazia(aux1)){
      inserir_fim(&lstm, aux1->dado);
      aux1=aux1->prox;
    }
  }
  else {
    while (!listaVazia(aux2)){
    inserir_fim(&lstm, aux2->dado);
    aux2=aux2->prox;
    }
  }

  //retorna a nova lista
  return lstm;
}
