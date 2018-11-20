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

struct item{
	int conteudo;
};

struct arvore{
	Item *i;
	struct arvore *direita;
	struct arvore *esquerda;
};

Item *criaItem(int valor){
	Item *I = (Item *) malloc(sizeof(Item));
	I->conteudo = valor;

	return I;
}

Arvore *criaArvore(){
	Arvore *A = (Arvore *) malloc(sizeof(Arvore));

	A->i = NULL;
	A->direita = NULL;
	A->esquerda = NULL;

	return A;
}

<<<<<<< HEAD
void insereItem(Arvore *A, int valor){
	if(!A)
		return;
	else{

=======
void insereItem(Arvore *A, int valor, int *erro){
	if(!A)
		A = criaArvore();
	if(!(A->i)){
		A->i = criaItem(valor);
		*erro = 0;
	}
	else{
		if(A->i->conteudo > valor)
			insereItem(A->esquerda, valor, erro);
		else if(A->i->conteudo < valor)
			insereItem(A->direita, valor, erro);
		else
			*erro = 1;
>>>>>>> e1ca64f4fde85a415b602ef4772fa78bbe7544bd
	}
}

void removeItem(Arvore *A, int valor){

}

int buscaItem(Arvore *A, int valor){
	if(!A)
		return 0;
	else{
		if(A->i->conteudo == valor)
			return 1;
		return valor > A->i->conteudo ? buscaItem(A->direita, valor) : buscaItem(A->esquerda, valor);
	}
}

void imprimeIN(Arvore *A){
	if(!A)
		return;
	else{
		imprimeIN(A->esquerda);
		printf(" %d", A->i->conteudo);
		imprimeIN(A->direita);
	}
}
void imprimePRE(Arvore *A){
	if(!A)
		return;
	else{
		printf(" %d", A->i->conteudo);
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
		printf(" %d", A->i->conteudo);
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
<<<<<<< HEAD
	printf("PreOrdem:");
	imprimePRE(A);
	printf("\n");
	printf("PosOrdem:");
	imprimePOS(A);
	printf("\n");
=======

	printf("PreOrdem:");
	imprimePRE(A);
	printf("\n");

	printf("PosOrdem:");
	imprimePOS(A);
	printf("\n");

>>>>>>> e1ca64f4fde85a415b602ef4772fa78bbe7544bd
	printf("Largura:");
	imprimeLargura(A);
	printf("\n");
}

void esvazia(Arvore *A){
	if(!A){
		esvazia(A->esquerda);
		esvazia(A->direita);
		free(A);
	}
}
