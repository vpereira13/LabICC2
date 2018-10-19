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
#include "fila.h"

int main (int argc, char *argv[]){
	int i;
	int ncasos;
	int carta;
	Item *I;
	Fila *baralho = criaFila();
	Fila *mesa = criaFila();

	// Pegando número de casos
	scanf("%d\n", &ncasos);

	// Para cada caso
	for(i = 0; i < ncasos; i++){
		// Coleta as cartas e coloca no baralho
		scanf("%d", &carta);
		while(carta){
			I = criaItem(carta);
			insere(baralho, I);

			scanf("%d", &carta);
		}
		// Roda o algoritmo de descarte e reposição
		while(tamanhoFila(baralho) != 1){
			I = retira(baralho);
			insere(mesa, I);
			I = retira(baralho);
			insere(baralho, I);
		}
		printf("Cartas jogadas: ");
		imprimeFila(mesa);
		printf("Cart restante: %d\n", valor(I));

		esvaziaFila(baralho);
		esvaziaFila(mesa);
	}

	free(baralho);
	free(mesa);
	free(I);
	
	return 0;
}