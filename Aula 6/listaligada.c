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
	int X;
	int Y;
};

typedef struct no No;

/*
 * Estrutura de um nó de uma lista, contém um item que é o conteúdo importante e
 * um ponteiro para o próximo nó
 */
struct no{
	Item *item;
	No* proximo;
};

/*
 * Estrutura da lista, contendo o tamanho dela e o ponteiro para o primeiro nó
 */
struct lista{
	int tamanho;
	No* primeiro;
};

/**
 * Função que alocamemória para uma lista e inicializa ela, com tamanho zero e o
 * primeiro item valendo NULL
 * @return uma lista alocada e com tamanho zero
 */
Lista *criaLista(){
	Lista *L = (Lista *) malloc(sizeof(Lista));

	L->tamanho = 0;
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
		return;
	}

	No *aux = L->primeiro;

	while(aux->proximo)
		aux = aux->proximo;
	aux->proximo = N;
	L->tamanho++;
}

/**
 * Função que imprime uma lista
 * @param L lista a ser impressa
 */
void imprimeLista(Lista *L){
	int i;

	if(estaVazia(L))
		return;

	No *aux = L->primeiro;

	for(i = 0; i < L->tamanho; i++){
		imprimeItem(aux->item);
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
void removeItem(Lista *L, int indice){
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
		Nanterior->proximo = N->proximo;
		free(N->item);
		free(N);
	}
}

/**
 * Função que retira o primeiro elemento da lista e retorna elemento
 * @param  L    lista a ser retirado o primeiro elemento
 * @return      primeiro elemento da lista
 */
Item *pop(Lista *L){
	Item *I;
	No *N;

	if(L->tamanho){
		N = L->primeiro;
		L->primeiro = N->proximo;
		L->tamanho--;
		I = criaItem(N->item->X, N->item->Y);
		N->proximo = NULL;
		free(N->item);
		free(N);
	}

	return I;
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
Item *criaItem(int X, int Y){
	Item *I = iniciaItem();

	I->X = X;
	I->Y = Y;

	return I;
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
int xItem(Item *I){
	return (I->X);
}

/**
 * Função que retorna o valor da coordenada Y de um item
 * @param  I item a ser analisado
 * @return   valor da coordenada Y do item
 */
int yItem(Item *I){
	return (I->Y);
}

/**
 * Função que imprime um dado do tipo item
 * @param I    item a ser impresso
 */
void imprimeItem(Item *I){
	int X = xItem(I);
	int Y = yItem(I);

	printf("X: %d\tY: %d\n", X, Y);
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
		if(aux->item->X == I->X && aux->item->Y == I->Y){
			return 1;
		}
		aux = aux->proximo;
	}
	return 0;
}