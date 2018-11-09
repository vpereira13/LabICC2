/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 9
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

void insere(Arvore *A, int valor){

}

void remove(Arvore *A, int valor){

}

int busca(Arvore *A, int valor){
	if(!A)
		return 0;
	else{
		if(A->valor == valor)
			return 1;
		return valor > A->valor ? busca(A->direita, valor) : busca(A->esquerda, valor);
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
	imprimeIN(A);
	imprimePRE(A);
	imprimePOS(A);
	imprimeLargura(A);
}