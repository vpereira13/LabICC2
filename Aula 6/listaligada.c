/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 6
 * Exercício 1 - Lista Backward
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include "listaligada.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Estrutura de um item, contém a coodenada X e a coordenada Y
 */
struct item{
	int chave;
	int tempo;
	int indiceBack;
	No* back;
};

typedef struct no No;

/*
 * Estrutura de um nó de uma lista, contém um item que é o conteúdo importante e
 * um ponteiro para o próximo nó
 */
struct no{
	Item *item;
	No *proximo;
};

/*
 * Estrutura da lista, contendo o tamanho dela e o ponteiro para o primeiro nó
 */
struct lista{
	int tamanho;
	int tempo;
	No *primeiro;
};

/**
 * Função que alocamemória para uma lista e inicializa ela, com tamanho zero e o
 * primeiro item valendo NULL
 * @return uma lista alocada e com tamanho zero
 */
Lista *criaLista(){
	Lista *L = (Lista *) malloc(sizeof(Lista));

	L->tamanho = 0;
	L->tempo = 0;
	L->primeiro = NULL;

	return L;
}

/**
 * Função que adiciona um item no inicio da lista
 * @param L lista a qual o item será inserido
 * @param I item a ser inserido
 */
void insereInicio(Lista *L, Item *I){
	No *N = (No *) malloc(sizeof(No));

	N->item = I;
	N->proximo = L->primeiro;
	L->primeiro = N;
	L->tamanho++;
	L->tempo++;
}

/**
 * Função que adiciona um item no final da lista
 * @param L lista a qual o item será inserido
 * @param I item a ser inserido
 */
void insereFim(Lista *L, Item *I){
	No *N = (No *) malloc(sizeof(No));
	N->item = I;
	N->proximo = NULL;

	if(!L->tamanho){
		L->primeiro = N;
		L->tamanho++;
		L->tempo++;
		return;
	}

	No *aux = L->primeiro;

	while(aux->proximo)
		aux = aux->proximo;
	aux->proximo = N;
	L->tamanho++;
	L->tempo++;
}

/**
 * Função que imprime uma lista
 * @param L lista a ser impressa
 */
void imprimeLista(Lista *L){
	int i;

	if(estaVazia(L)){
		printf("-1\n");
		return;
	}

	No *aux = L->primeiro;

	for(i = 0; i < L->tamanho; i++){
		imprimeItem(aux->item);
		if(i != L->tamanho - 1)
			printf(" ");
		aux = aux->proximo;
	}

	printf("\n");
}

/**
 * Função que verifica se a lista dada está vazia ou não
 * @param  L lista a ser analisada
 * @return   retorna se está vazia ou não
 */
char estaVazia(Lista *L){
	return (L->tamanho == 0);
}

/**
 * Função que retorna o tamanho de uma lista
 * @param  L lista a ser analisada
 * @return   tamanho da lista
 */
int tamanhoLista(Lista *L){
	return (L->tamanho);
}

int tempoLista(Lista *L){
	return (L->tempo);
}

/**
 * Função responsável por esvaziar a lista, liberando toda a memória alocada
 * @param L lista a ser esvaziada
 */
void esvaziaLista(Lista *L){
	No *N;

	while(L->tamanho > 0){
		N = L->primeiro;
		L->primeiro = N->proximo;
		L->tamanho--;
		N->proximo = NULL;
		free(N->item);
		free(N);
	}
}

/**
 * Função que remove o item dado um índice de uma dada lista
 * @param L      lista que terá o item removido
 * @param indice índice do item a ser removido
 */
void removeIndice(Lista *L, int indice){
	int i;
	No *N = NULL;
	No *Nanterior = NULL;

	if(indice >= 0 && indice < L->tamanho){
		N = L->primeiro;
		Nanterior = L->primeiro;
		for(i = 0; i < indice; i++){
			Nanterior = N;
			N = N->proximo;
		}
		L->tamanho--;
		L->tempo++;
		Nanterior->proximo = N->proximo;
		free(N->item);
		free(N);
	}
}

/**
 * Função que remove o item que tem uma chave igual a chave dada
 * @param L      lista que terá o item removido
 * @param chave índice do item a ser removido
 */
void removeItem(Lista *L, int chave){
	int i;
	int tamanho = tamanhoLista(L);
	No *N = NULL;
	No *Nanterior = NULL;

	N = L->primeiro;
	Nanterior = L->primeiro;

	// Caso primeiro elemento
	if(chaveItem(N->item) == chave){
		L->primeiro = N->proximo;
		L->tamanho--;
		L->tempo++;
		free(N->item);
		free(N);
		return;
	}

	// Caso contrário, procura no resto
	for(i = 0; i < tamanho; i++){
		if(chaveItem(N->item) == chave){
			Nanterior->proximo = N->proximo;
			L->tamanho--;
			L->tempo++;
			free(N->item);
			free(N);
			return;
		}
		else{
			Nanterior = N;
			N = N->proximo;
		}
	}
	return;
}

/**
 * Função que aloca espaço de memória para um item e retorna ele, mas sem
 * conteúdo
 * @return item alocado, mas sem conteúdo
 */
Item *iniciaItem(){
	Item *I = (Item *) malloc(sizeof(Item));

	return I;
}

/**
 * Função que cria um item, alocando espaço e colocando os valores dados
 * @param  X    valor da coordenada X
 * @param  X    valor da coordenada Y
 * @return      item alocado e com conteúdo
 */
Item *criaItem(int chave, int tempo){
	Item *I = iniciaItem();

	I->chave = chave;
	I->tempo = tempo;
	I->indiceBack = -1;
	I->back = NULL;

	return I;
}

void criaEInsere(Lista *L, int n, int back){
	int i;
	int tamanho = tamanhoLista(L);
	Item *I = criaItem(n, tempoLista(L));
	No *N = (No *) malloc (sizeof(No));

	// Caso possível linkar
	if(back && back <= tamanho){
		N = L->primeiro;
		for(i = 0; i < tamanho; i++)
			N = N->proximo;
		I->back = N;
		I->indiceBack = tamanho - back;
	}

	insereFim(L, I);
}

/**
 * Função que retorna um item que está numa dada posição
 * @param  L      lista a ser analisada
 * @param  indice índice do item a ser encontrado
 * @return        item que está na posição dada
 */
Item *naPosicao(Lista *L, int indice){
	int i;
	No *N = NULL;

	if(indice >= 0 && indice < L->tamanho){
		N = L->primeiro;
		for(i = 0; i < indice; i++)
			N = N->proximo;
	}
	return N->item;
}

/**
 * Função que retorna o valor da coordenada X de um item
 * @param  I item a ser analisado
 * @return   valor da coordenada X do item
 */
int chaveItem(Item *I){
	return (I->chave);
}

/**
 * Função que retorna o valor da coordenada Y de um item
 * @param  I item a ser analisado
 * @return   valor da coordenada Y do item
 */
int tempoItem(Item *I){
	return (I->tempo);
}

int indiceItem(Item *I){
	return (I->indiceBack);
}

/**
 * Função que imprime um dado do tipo item
 * @param I    item a ser impresso
 */
void imprimeItem(Item *I){
	int chave = chaveItem(I);
	int tempo = tempoItem(I);
	int indiceBack = indiceItem(I);

	if(indiceBack >= 0 && I->back != NULL)
		printf("[%d,%d,%d]", chave, tempo, indiceBack);
	else
		printf("[%d,%d]", chave, tempo);
}

/**
 * Função que verifica se um item está na lista ou não
 * @param  L lista a ser analisada
 * @param  I item a ser encontrado
 * @return   Resultado da procura
 *               0 - se não estiver na lista
 *               1 - se estiver na lista
 */
int estaNaLista(Lista *L, Item *I){
	No *aux = L->primeiro;

	while(aux != NULL){
		if(aux->item->chave == I->chave && aux->item->tempo == I->tempo){
			return 1;
		}
		aux = aux->proximo;
	}
	return 0;
}