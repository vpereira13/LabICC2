/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 10
 * Exercício 1 - Editor de Árvore Binária de Busca
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore{
	int valor;
	struct arvore *direita;
	struct arvore *esquerda;
};

Arvore *criaArvore(){
	Arvore *A = (Arvore *) malloc(sizeof(Arvore));

	A->direita = NULL;
	A->esquerda = NULL;

	return A;
}

void insereItem(Arvore *A, int valor){
	if(!A)
		return;
	else{

	}
}

void removeItem(Arvore *A, int valor){

}

int buscaItem(Arvore *A, int valor){
	if(!A)
		return 0;
	else{
		if(A->valor == valor)
			return 1;
		return valor > A->valor ? buscaItem(A->direita, valor) : buscaItem(A->esquerda, valor);
	}
}

void imprimeIN(Arvore *A){
	if(!A)
		return;
	else{
		imprimeIN(A->esquerda);
		printf(" %d", A->valor);
		imprimeIN(A->direita);
	}
}
void imprimePRE(Arvore *A){
	if(!A)
		return;
	else{
		printf(" %d", A->valor);
		imprimeIN(A->esquerda);
		imprimeIN(A->direita);
	}
}
void imprimePOS(Arvore *A){
	if(!A)
		return;
	else{
		imprimeIN(A->esquerda);
		imprimeIN(A->direita);
		printf(" %d", A->valor);
	}
}
void imprimeLargura(Arvore *A){
	if(!A)
		return;
}

void imprimeTodos(Arvore *A){
	printf("InOrdem:");
	imprimeIN(A);
	printf("\n");
	printf("PreOrdem:");
	imprimePRE(A);
	printf("\n");
	printf("PosOrdem:");
	imprimePOS(A);
	printf("\n");
	printf("Largura:");
	imprimeLargura(A);
	printf("\n");
}

void esvazia(Arvore *A){

}