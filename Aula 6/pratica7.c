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
			tempo (pegar da lista)
			ponteiro para o “back”
			e ponteiro para o próximo
 */

void criaEInsere(Lista *L, int n, int back){
	Item *I = criaItem(n, tempoLista(L));

	insereFim(L, I);
}

int main (int argc, char *argv[]){
	int n;
	int back;
	char operacao;
	Lista *L = criaLista();

	// Coletando entrada
	while(scanf("%c %d %d\n", &operacao, &n, &back) > 1 && operacao != 'f'){
		if(operacao == 'i'){
			criaEInsere(L, n, back);
			imprimeLista(L);
		}
		else if(operacao == 'r'){
			// Caso de remoção
			removeItem(L, n);
		}
	}

	// Imprimindo
	imprimeLista(L);

	// Liberando memória
	esvaziaLista(L);
	free(L);

	return 0;
}