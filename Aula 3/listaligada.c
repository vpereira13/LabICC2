/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 3
 * Exercício 1 - Cálculo da Derivada e Reta Tangente
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include "listaligada.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Estrutura de um item, contém um coeficiente e um expoente, lembrando que o
 * coeficiente pode ser maior que um inteiro
 */
struct item{
	long int coeficiente;
	int expoente;
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
 * Função que imprime uma lista (equação)
 * @param L lista a ser impressa
 */
void imprimeLista (Lista* L){
	int i;

	if(estaVazia(L))
		return;

	No *aux = L->primeiro;

	for(i = 0; i < L->tamanho; i++){
		imprimeItem(aux->item, i);
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
 * @param  coeficiente valor do coeficiente
 * @param  expoente    valor do expoente
 * @return             item alocado e com conteúdo
 */
Item *criaItem(long int coeficiente, int expoente){
	Item *I = iniciaItem();

	I->coeficiente = coeficiente;
	I->expoente = expoente;

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
 * Função que imprime um dado do tipo item da forma certa para cada tipo de
 * parte da função
 * @param I        item a ser impresso
 * @param primeiro parametro auxiliar para dizer se é o primeiro item de uma
 * função, pois se for e o valor do coeficiente for positivo, ele não pode
 * conter o sinal
 */
void imprimeItem(Item *I, int primeiro){
	int expoente = expoenteItem(I);
	long int coeficiente = coeficienteItem(I);

	// Tratamento do sinal do primeiro elemento
	if(coeficiente < 0)
		printf("- ");
	else if(primeiro)
			printf("+ ");

	if(expoente > 1)
		printf("%ldx^%d ", labs(coeficiente), expoente);
	else if(expoente == 1)
		printf("%ldx ",  labs(coeficiente));
	else
		printf("%ld",  labs(coeficiente));
}

/**
 * Função que retorna o valor do coeficiente de um item
 * @param  I item a ser analisado
 * @return   valor do coeficiente do item
 */
long int coeficienteItem(Item *I){
	return (I->coeficiente);
}

/**
 * Função que retorna o valor do expoente de um item
 * @param  I item a ser analisado
 * @return   valor do expoente do item
 */
int expoenteItem(Item *I){
	return (I->expoente);
}

Item *removeItem (int indice, Lista *L){
	int i;
	int tamanho;
	No *pai;
	No *seguinte;
	Item *it;

	it = iniciaItem();
	tamanho = tamanhoLista(L);

	// Caso a lista esteja vazia ou não exista essa posição
	if(estaVazia(L) || indice >= tamanho)
		return NULL;

	pai = L->primeiro;

	for(i = 0; i < indice; i++)
		pai = pai->proximo;

	seguinte = pai->proximo;
	it = seguinte->item;

	pai->proximo = seguinte->proximo;

	return it;
}