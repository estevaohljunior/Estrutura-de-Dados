// Definição da estrutura pilha encadeada
typedef struct nopilha {
	int dado;	// campo que guarda a informacao
	struct nopilha *prox; // guarda o endereço para prox nó
}no;
typedef no* TPilhaEnc;

//************** Interface de uso do TAD Pilha Sequencial **************//


/* Criar uma pilha vazia */
void criarPilha( TPilhaEnc *pilha );

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilhaEnc pilha );

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha );

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado );

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado );

/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado );

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha );


/******************************************/


/* Clonar pilha de origem em pilha de destino*/
int clonar (TPilhaEnc *origem, TPilhaEnc *destino);

/* Sub-rotina de alocação dinamica*/
TPilhaEnc aloca();
