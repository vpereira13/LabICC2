/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 9
 * Exercício 2 - Tabela Hash <>
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(int argc, char *argv[]){
	int resultado;
	char operacao;
	char *palavra;

	// Cria a tabela hash
	Hash *H = cria_hash(365);

	// Aloca tamanho para a palavra
	palavra = (char *) malloc(sizeof(char) * 30);

	scanf("%c %s\n", &operacao, palavra);

	while(operacao != 'f'){
		// Analisa entrada
		switch (operacao){
			// Caso de insercao
			case 'i':
				insere(H, palavra);
			break;
			// Caso de busca
			case 'b':
				resultado = busca(H, palavra);
				resultado ? printf("encontrado\n") : printf("nao encontrado\n");
			break;
			// Caso de remocao
			case 'r':
				remove_item(H, palavra);
			break;
		}

		// Pegando a próxima entrada
		scanf("%c %s\n", &operacao, palavra);
	}

	// Liberando memória
	free(palavra);
	esvazia_hash(H);
	free(H);

	return 0;
}
