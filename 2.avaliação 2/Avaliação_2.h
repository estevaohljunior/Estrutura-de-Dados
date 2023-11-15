typedef struct nolista {
	float dado;  			   // campo que guarda a informação
  struct nolista *prox;  // guarda o endereço para prox nó
  struct nolista *ant;   // guarda o endereço para nó anterior
}no;

typedef no* TListaDupEnc;

void criarLista( TListaDupEnc *lista );

int listaVazia( TListaDupEnc lista );

int tamanhoLista( TListaDupEnc lista );

int elementoNaPosicao( TListaDupEnc lista, int posicao, int* dado );

int posicaoDoElemento( TListaDupEnc lista, int dado );

int inserirElemento( TListaDupEnc* lista, int posicao, int dado );

int removerElemento( TListaDupEnc* lista, int posicao, int *dado );

void imprimir ( TListaDupEnc lista );



TListaDupEnc aloca();


// NOVAS FUNÇÕES E VARIÁVEIS !!!!!

int n_elementos=0;

int num_ocorrencias ( TListaDupEnc lista, float  dado);

int inserir_inicio( TListaDupEnc *lista, float dado);

int inserir_fim ( TListaDupEnc *lista, float dado);

int rm_inicio( TListaDupEnc *lista);

int rm_fim( TListaDupEnc *lista);

TListaDupEnc merge(TListaDupEnc *lst1, TListaDupEnc *lst2);

void finaliza_insercao ();
