/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 1
 * Exercício 2 - Operações Básicas
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoes.h"

#define S "SOMA"
#define SB "SUBTRACAO"
#define M "MULTIPLICACAO"
#define D "DIVISAO"
#define MAX 70

int main(int argc, char *argv[]) {
	char *stringA;
	char *stringB;
	int *inteiroA;
	int *inteiroB;
	int *resultado = NULL;
	char operacao[15];

	// Lendo tipo de operação
	scanf("%s", operacao);

	// Alocando memória para as strings
	stringA = (char *) malloc (MAX * sizeof(char));
	stringB = (char *) malloc (MAX * sizeof(char));

	// Lendo os inteiros em forma de string
	scanf("%s", stringA);
	scanf("%s", stringB);

	// Transformando as strings em vetores de inteiros
	inteiroA = char2int(stringA);
	inteiroB = char2int(stringB);

	if(!strcmp(operacao, S))
		resultado = soma(inteiroA, inteiroB);

	else if(!strcmp(operacao, SB))
		resultado = subtracao(inteiroA, inteiroB);

	else if(!strcmp(operacao, M))
		resultado = multiplicacao(inteiroA, inteiroB);

//	else if(!strcmp(operacao, D))
//		resultado = divisao(inteiroA, inteiroB);

	if(resultado)
		imprimeInteiro(resultado);

	// Liberando memória das strings
	free(stringA);
	free(stringB);
	// Liberando memória dos inteiros
	free(inteiroA);
	free(inteiroB);
	free(resultado);

	return 0;
}
