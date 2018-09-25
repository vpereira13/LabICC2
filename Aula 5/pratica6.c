/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 5
 * Exercício 1 - Pintura de tela
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

/**
 * TODO
 *  - Consertar todos os erros e desalocar toda a memória alocada
 */

void verificaInsere(Lista *L, char **tela, char tinta, int coordX, int coordY, int xmax, int ymax){
	Item *I = criaItem(coordX, coordY);

	if(!estaNaLista(L, I))
		insereFim(L, I);
	else
		return;

	// verifica cima, baixo, direita e esquerda se é igual, se for tenta adicionar
	if(coordX >= 0 && coordX < xmax && coordY >= 0 && coordY < ymax){
		// cima
		if(coordY - 1 >=  0 && tela[coordX][coordY - 1] == tinta)
			verificaInsere(L, tela, tinta, coordX, coordY - 1, xmax, ymax);
		// baixo
		if(coordY + 1 < ymax && tela[coordX][coordY + 1] == tinta)
			verificaInsere(L, tela, tinta, coordX, coordY + 1, xmax, ymax);
		// direita
		if(coordX + 1 < xmax && tela[coordX + 1][coordY] == tinta)
			verificaInsere(L, tela, tinta, coordX + 1, coordY, xmax, ymax);
		// esquerda
		if(coordX - 1 >= 0 && tela[coordX - 1][coordY] == tinta)
			verificaInsere(L, tela, tinta, coordX - 1, coordY, xmax, ymax);
	}
}

void preencheLista(Lista *L, char **tela, int coordX, int coordY, int x, int y){
	char tinta = tela[coordX][coordY];
	verificaInsere(L, tela, tinta, coordX, coordY, x, y);
}

void coloreTela(char **tela, Lista *L, char tinta){
	int i;
	Item *I;

	for(i = 0; i < tamanhoLista(L); i++){
		I = naPosicao(L, i);
		tela[xItem(I)][yItem(I)] = tinta;
	}
}

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
	Lista *L;

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

	L = criaLista();

	// Recebendo a posição e a tinta a ser preenchida na tela
	while(scanf("%d %d %c\n", &coordX, &coordY, &tinta) != EOF){
		// Cria a lista contendo as posições a serem pintadas
		preencheLista(L, tela, coordX, coordY, x, y);

		// Colorindo a tela
		coloreTela(tela, L, tinta);

		// Liberando memória de cada lista criada
		esvaziaLista(L);

		// Imprime a tela colorida
		imprimeTela(tela, x);
	}

	imprimeLista(L);

	// Liberando dados alocados
	for(i = 0; i < x; i++)
		free(tela[i]);
	free(tela);

	return 0;
}
