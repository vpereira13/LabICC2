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


/*
	Estrutura utilizada
		Lista ligada com:
			Chave
			ponteiro para o “back”
			e ponteiro para o próximo
 */

int main (int argc, char *argv[]){
	int n;
	int back;
	char operacao;
	Lista *L = criaLista();
	Item *I = NULL;

	// Coletando entrada
	while(scanf("%c %d %d\n", &operacao, &n, &back) > 1 && operacao != 'f'){
		if(operacao == 'i'){
			I = criaItem(n, back);
			insereFim(L, I);
			imprimeLista(L);
		}
		else if(operacao == 'r')
			removeItem(L, n);
	}

	imprimeLista(L);
	esvaziaLista(L);
	free(L);

	return 0;
}