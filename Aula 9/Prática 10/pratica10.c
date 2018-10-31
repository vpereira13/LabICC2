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
#include "arvore.h"

int main (int argc, char *argv[]){
	int i;
	int ncasos;
	int iteracao;
	char *str_arvore1;
	char *str_arvore2;
	Arvore *arvore1;
	Arvore *arvore2;

	scanf("%d\n", &ncasos);

	str_arvore1 = (char *) malloc (sizeof(char) * 1024);
	str_arvore2 = (char *) malloc (sizeof(char) * 1024);

	for(i = 0; i < ncasos; i++){
		scanf("%s\n", str_arvore1);
		scanf("%s\n", str_arvore2);

		arvore1 = inicia_arvore();
		iteracao = 0;
		cria_arvore(arvore1, str_arvore1, &iteracao);

		arvore2 = inicia_arvore();
		iteracao = 0;
		cria_arvore(arvore2, str_arvore2, &iteracao);
	}

	free(str_arvore1);
	free(str_arvore2);

	return 0;
}
