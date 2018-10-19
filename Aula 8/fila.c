/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 8
 * Exercício 1 - Cartas
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct item{
	int valor;
};

typedef struct no No;

struct no{
	Item *item;
	No* proximo;
};

struct fila{
	No *primeiro;
	int tamanho;
};

/**
 * Função que aloca memória para uma fila e inicializa ela, com tamanho zero e
 * primeiro item sendo nulo
 * @return uma fila alocada e com tamanho zero
 */
Fila *criaFila(){
	Fila *F = (Fila *) malloc(sizeof(Fila));

	F->tamanho = 0;
	F->primeiro = NULL;

	return F;
}

/**
 * Função que adiciona um item no final da fila
 * @param F fila que vai receber o item
 * @param I item a ser inserido na fila
 */
void insere(Fila *F, Item *I){
	No *N = (No *) malloc(sizeof(No));

	N->item = I;
	N->proximo = NULL;

	if(!F->tamanho){
		F->primeiro = N;
		F->tamanho++;
		return;
	}
	else{
		No *aux = F-> primeiro;
		while(aux->proximo)
			aux = aux->proximo;
		aux->proximo = N;
		F->tamanho++;
	}
}

/**
 * Função para imprimir a fila
 * @param F fila a ser impressa
 */
void imprimeFila(Fila *F){
	int i;
	int tamanho = tamanhoFila(F);

	if(!tamanho)
		return;

	No *aux = F->primeiro;

	for(i = 0; i < tamanho; i++) {
		imprimeItem(aux->item);
		aux = aux->proximo;
	}
	printf("\n");
}

/**
 * Função que verifica se a fila está vazia ou não
 * @param  F fila a ser analisada
 * @return   retorna se a fila está vazia ou não
 */
char estaVazia(Fila *F){
	return (F->tamanho == 0);
}

/**
 * Função que retorna o tamanho da fila
 * @param  F fila a ser analisada
 * @return   tamanho da fila
 */
int tamanhoFila(Fila *F){
	return (F->tamanho);
}

/**
 * Função para esvaziar uma fila
 * @param F fila a ser esvaziada
 */
void esvaziaFila(Fila *F){
	No *N;

	while(F->tamanho > 0){
		N = F->primeiro;
		F->primeiro = N->proximo;
		F->tamanho--;

		N->proximo = NULL;
		free(N->item);
		free(N);
	}
}

/**
 * Função que retira o primeiro item da fila e retorna
 * @param  F fila a ter o item retirado
 * @return   primeiro item da fila
 */
Item *retira(Fila *F){
	Item *I;
	No *N;

	if(F->tamanho){
		N = F->primeiro;
		F->primeiro = N->proximo;
		F->tamanho--;
		I = criaItem(N->item->valor);
		N->proximo = NULL;
		free(N->item);
		free(N);
	}

	return I;
}

/**
 * Função para iniciar um item, só alocando memória para um item
 * @return espaço de memória alocado para um item
 */
Item *iniciaItem(){
	Item *I = (Item *) malloc(sizeof(Item));

	return I;
}

/**
 * Função que cria um item já inicializando o valor dele
 * @param  valor valor do item criado
 * @return       item alocado e com conteúdo
 */
Item *criaItem(int valor){
	Item *I = iniciaItem();

	I->valor = valor;

	return I;
}

/**
 * Função que imprime o dado de um tipo item
 * @param I item a ser impresso
 */
void imprimeItem(Item *I){
	printf(" %d", I->valor);
}

/**
 * Função que retorna o valor de um item
 * @param  I      item a ser analisado
 * @return        valor do item
 */
int valor(Item *I){
	return I->valor;
}