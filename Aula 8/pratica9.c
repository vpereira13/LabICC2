/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 8
 * Exercício 1 - Cartas
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	int i;
	int ncasos;
	int carta;

	// Pegando número de casos
	scanf("%d\n", &ncasos);

	// Para cada caso
	for(i = 0; i < ncasos; i++){
		// Coleta as cartas e coloca na estrutura
		scanf("%d", &carta);
		while(carta){
			// Adicionar carta na estrutura
			scanf("%d", &carta);
		}
		// Roda o algoritmo de descarte e reposição
	}

	return 0;
}