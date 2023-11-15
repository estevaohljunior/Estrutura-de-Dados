#include <stdio.h>
#include <stdlib.h>
#include "avaliacao_2.h"

int main(void){
  float lista1[3]={2.1, 4.5, 1.0}, lista2[3]={7.2, 3.1,9.8};
  

  TListaDupEnc l;

  criarLista(&l);

  int opc=0;

  while ( 1 ){
    printf("\nDigite um numero da lista e em seguida\npressione enter para executar.\n\n0 - para encerrar o programa.\n1 - Para verificar o número de ocorrencias de um item.\n2 - Inserir elemento no inicio da lista.\n3 - Inserir elemento no fim da lista.\n4 - Remover primeiro elemento.\n5 - Remover ultimo elemento.\n6 - Para imprimir a lista na tela.\n\nOpção: ");
    scanf("%d",&opc);

    if (opc==0) break;

    else if (opc==1){
      int  resultado=0;
      float n_ver=0;
      if (listaVazia(l))
        printf("Opção indisponível. Lista VAZIA!\n");
      
      else{
        printf("Digite o número a ser verificado na lista: ");
        scanf("%f", &n_ver);
      
        resultado=num_ocorrencias(l, n_ver);

        if(resultado==0) printf("Não há incidências do número na lista.\n");
        else printf("O número de ocorrências na lista é de %d.\n", resultado);
      }
    }

    else if (opc==2){
      float n_ini=0;
      printf("Digite o número a ser inserido no inicio da lista: ");
      scanf("%f", &n_ini);
      inserir_inicio(&l, n_ini);
    }

    else if (opc==3){
      float n_fim=0;
      printf("Digite o número a ser inserido no fim da lista: ");
      scanf("%f", &n_fim);
      inserir_fim(&l, n_fim);
    }

    else if (opc==4){
      float *n_ini=0;
      rm_inicio(&l);
    }

    else if (opc==5){
      float *n_ini=0;
      rm_fim(&l);
    }

    else if (opc==6)imprimir(l);

    else printf("\nNúmero inválido! por favor escolha uma opcao válida.\n\n");
  }

  l=NULL;
  imprimir(l);
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

/*FUNÇÃO QUE CONTABILIZA O NUMERO DE OCORRENCIAS DE UM ITEM*/
int num_ocorrencias(TListaDupEnc lista, float dado){
    int numero=dado,contador = 0;

	  for( ;!listaVazia( lista ); lista = lista->prox ){
      if (lista->dado==numero) contador++;
    }
    return contador;
}

/*SUB-ROTINA DE ALOCAÇÃO DINAMICA*/
TListaDupEnc aloca(){
  return (TListaDupEnc) malloc(sizeof(TListaDupEnc));
}

/*FUNÇÃO PARA INSERIR UM ELEMENTO NO INICIO DA LISTA*/
int inserir_inicio(TListaDupEnc *lista, float dado){
	TListaDupEnc novo = NULL, aux = NULL;
  n_elementos++;
    // inserção em uma lista que está vazia
    if( listaVazia( *lista ) ) {
		// alocar o no e testar pra ver se tudo correu bem
      if( ( novo = aloca() ) == NULL ) return 0;
        novo->dado = dado;
        novo->prox = NULL;
        novo->ant = NULL;
        *lista = novo;

        return 1;
    }

	// inserção na primeira posição em uma lista não vazia
    // alocar o no e testar pra ver se tudo correu bem
    if( ( novo = aloca() ) == NULL ) return 0;
      novo->dado = dado;
      novo->prox = *lista; // faz novo nó "conectar-se" ao primeiro
      novo->ant = NULL;
      (*lista)->ant = novo;
      *lista = novo;
      return 1;

    // inserção após a primeira posição e em uma lista não vazia
    aux = *lista;

    return 1;
}

/* FUNÇÃO PARA INSERIR ELEMENTO AO FIM DA LISTA*/
int inserir_fim ( TListaDupEnc* lista, float dado ){
	TListaDupEnc novo = NULL, aux = NULL;
  int contador = 1;
  n_elementos++;
  // inserção em uma lista que está vazia
    if( listaVazia( *lista ) ) {
    // se a lista está vazia, só é possível inserir na posição 1
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

/* FUNÇÃO PARA REMOVER O PRIMEIRO ITEM DA LISTA */
int rm_inicio( TListaDupEnc *lista){
  TListaDupEnc aux = NULL;
    int contador = 1;
    n_elementos--;

    if ( listaVazia( *lista ) ) return 0;

    // faz aux apontar para o primeiro elemento
    aux = *lista;

    // aux deve "parar" sobre o nó a ser removido
    while( ( contador < 1) && ( aux != NULL ) ){
    	aux = aux->prox;
        contador++;
    }

    // primeiro nó da lista
    	*lista = aux->prox;
        // deve-se testar se há mais de um elemento na lista
        if( aux->prox != NULL )	aux->prox->ant = NULL;
 
    // remover, aqui, implica em desalocar memória
    free( aux );
    return 1;
}

int rm_fim( TListaDupEnc *lista){
  TListaDupEnc aux = NULL;
    int contador = 1;

    if ( listaVazia( *lista ) ) return 0;

    // faz aux apontar para o primeiro elemento
    aux = *lista;

    // aux deve "parar" sobre o nó a ser removido
    while( ( contador < n_elementos ) && ( aux != NULL ) ){
    	aux = aux->prox;
        contador++;
    }
    
    // primeiro nó da lista?
    if( n_elementos == 1 ){
    	*lista = aux->prox;
        // deve-se testar se há mais de um elemento na lista
        if( aux->prox != NULL )	aux->prox->ant = NULL;
    } else {
    	// se não é o último nó...
        if( aux->prox != NULL ) aux->prox->ant = aux->ant;

        aux->ant->prox = aux->prox;
    }
    // remover, aqui, implica em desalocar memória
    n_elementos--;
    free( aux );
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
	if ( !listaVazia(lista) ){
  printf("\nNúmero de elementos na lista: %d", tamanhoLista(lista));
  printf( "\nLista: ( ");

	for( ;!listaVazia( lista ); lista = lista->prox )
	    printf("%.1f ", lista->dado );

	printf( ")\n" );
  }
  else printf("\nImpossível imprimir. LISTA VAZIA!\n");
}

