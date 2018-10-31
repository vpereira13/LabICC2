/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 9
 * Exercício 1 - Imagens
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore{
	char tipo;
	struct arvore *esquerda;
	struct arvore *direita;
	struct arvore *meio_esquerda;
	struct arvore *meio_direita;
};

/**
 * Função que aloca memória necessária para uma árvore, nesse caso uma árvore
 * quaternária
 * @return ponteiro para uma área alocada da memória
 */
Arvore *inicia_arvore(){
	Arvore *A = (Arvore *) malloc(sizeof(Arvore));

	A->esquerda = NULL;
	A->direita = NULL;
	A->meio_esquerda = NULL;
	A->meio_direita = NULL;

	return A;
}

/**
 * Função para criar a árvore de forma recursiva a partir da string de entrada
 * @param A	  árvore a ser gerada
 * @param string string que representa a árvore
 * @param i	  iteração para ter controle da parte da string
 */
void cria_arvore(Arvore *A, char *string, int *i){
	int tamanho;
	tamanho = strlen(string);
	if(*i < tamanho){
		A->tipo = string[(*i)++];

		if(A->tipo == 'p'){
			A->esquerda = inicia_arvore();
			cria_arvore(A->esquerda, string, i);
			A->meio_esquerda = inicia_arvore();
			cria_arvore(A->meio_esquerda, string, i);
			A->meio_direita = inicia_arvore();
			cria_arvore(A->meio_direita, string, i);
			A->direita = inicia_arvore();
			cria_arvore(A->direita, string, i);
		}
		else
			return;
	}
	else
		return;
}

/**
 * Função que mistura duas árvores de entrada e a segunda árvore fica como
 * resultado da mistura
 * @param A primeira árvore a ser analisada
 * @param B segunda árvore a ser analisada e resultado da mistura
 */
void mistura_arvores(Arvore *A, Arvore *B){
	// Caso a árvore A for cheia, a B tem que ser cheia
	if(A->tipo == 'f'){
		B->tipo = 'f';
		return;
	}
	// Caso a árvore A for vazia, a B tem que manter o que ela tem
	else if (A->tipo == 'e')
		return;
	// Caso a árvore A for do tipo pai
	else if (A->tipo == 'p'){
		// Caso a árvore B for cheia, mantém cheia
		if (B->tipo == 'f')
			return;
		// Caso a árvore B for vazia, então ela recebe o conteúdo da árvore A
		else if (B->tipo == 'e'){
			B->tipo = 'p';
			B->esquerda = A->esquerda;
			B->meio_esquerda = A->meio_esquerda;
			B->direita = A->direita;
			B->meio_direita = A->meio_direita;
			return;
		}
		// Caso a árvore B for do tipo pai, tem que ser analisado cada filho
		else if (B->tipo == 'p'){
			mistura_arvores(B->esquerda, A->esquerda);
			mistura_arvores(B->meio_esquerda, A->meio_esquerda);
			mistura_arvores(B->direita, A->direita);
			mistura_arvores(B->meio_direita, A->meio_direita);
		}
	}
}