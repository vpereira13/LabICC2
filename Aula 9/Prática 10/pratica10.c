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

int main (int argc, char *argv[]){
	int i;
	int ncasos;
	char *str_arvore1;
	char *str_arvore2;

	scanf("%d\n", &ncasos);

	str_arvore1 = (char *) malloc (sizeof(char) * 1024);
	str_arvore2 = (char *) malloc (sizeof(char) * 1024);

	for(i = 0; i < ncasos; i++){
		scanf("%s\n", str_arvore1);
		scanf("%s\n", str_arvore2);
	}

	free(str_arvore1);
	free(str_arvore2);

	return 0;
}
