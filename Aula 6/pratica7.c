/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 6
 * Exercício 1 - Lista Backward
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

int main (int argc, char *argv[]){
	int n;
	int back;
	char operacao;
	Lista *L = criaLista();

	// Coletando entrada
	while(scanf("%c %d %d\n", &operacao, &n, &back) > 1 && operacao != 'f'){
		if(operacao == 'i')
			// Caso de inserção
			criaEInsere(L, n, back);
		else if(operacao == 'r')
			// Caso de remoção
			removeItem(L, n);
	}

	// Imprimindo
	imprimeLista(L);

	// Liberando memória
	esvaziaLista(L);
	free(L);

	return 0;
}