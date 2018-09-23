/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 4
 * Exercício 1 - Campeonato desordenado
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>


void imprimeTela(char **tela, int x){
	int i;
	for(i = 0; i < x; i++)
		printf("%s\n", tela[i]);
}

int main (int argc, char *argv[]){
	int i;
	int j;
	int x;
	int y;
	int coordX;
	int coordY;
	char tinta;
	char lixo;
	char **tela;

	scanf("%d %d\n", &x, &y);

	// Alocando memória da tela
	tela = (char **) malloc (sizeof(char *) * x);
	for(i = 0; i < x; i++)
		tela[i] = (char *) malloc (sizeof(char) * y);

	// Recebendo o conteúdo da tela
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++)
			scanf("%c", &tela[i][j]);
		scanf("%c", &lixo);
	}

	// Recebendo a posição e a tinta a ser preenchida na tela
	while(scanf("%d %d %c\n", &coordX, &coordY, &tinta) != EOF){
		// pegar a lista dos adjacentes e fazer a coloração
		imprimeTela(tela, x);
	}

	return 0;
}
