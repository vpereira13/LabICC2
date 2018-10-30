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
 * @param A      árvore a ser gerada
 * @param string string que representa a árvore
 * @param i      iteração para ter controle da parte da string
 */
void cria_arvore(Arvore *A, char *string, int i){
	int tamanho;
	tamanho = strlen(string);
	if(i < tamanho){
		A->tipo = string[i++];

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

void mistura_arvores(Arvore *A, Arvore *B){
	if(A->tipo == '')

}