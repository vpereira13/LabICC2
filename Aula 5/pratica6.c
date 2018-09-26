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
 *  - Liberar memória de forma correta, ainda tem vazamento
 */

void coloreTela(char **tela, Lista *L, char tinta){
	int i;
	Item *I;

	for(i = 0; i < tamanhoLista(L); i++){
		I = naPosicao(L, i);
		tela[xItem(I)][yItem(I)] = tinta;
	}
}

void geraLista(char **tela, char tintaNova, int x, int y, int xmax, int ymax){
	int X;
	int Y;
	Lista *L = criaLista();
	Item *I = criaItem(x, y);
	insereInicio(L, I);

	while(tamanhoLista(L)){
		I = pop(L);
		X = xItem(I);
		Y = yItem(I);

		// Cima
		if(Y - 1 >= 0 && tela[X][Y - 1] == tela[X][Y]){
			I = criaItem(X, Y - 1);
			if(!estaNaLista(L, I))
				insereInicio(L, I);
		}
		// Baixo
		if(Y + 1 < ymax && tela[X][Y + 1] == tela[X][Y]){
			I = criaItem(X, Y + 1);
			if(!estaNaLista(L, I))
				insereInicio(L, I);
		}
		// Direita
		if(X + 1 < xmax && tela[X + 1][Y] == tela[X][Y]){
			I = criaItem(X + 1, Y);
			if(!estaNaLista(L, I))
				insereInicio(L, I);
		}
		// Esquerda
		if(X - 1 >= 0 && tela[X - 1][Y] == tela[X][Y]){
			I = criaItem(X - 1, Y);
			if(!estaNaLista(L, I))
				insereInicio(L, I);
		}
		tela[X][Y] = tintaNova;
	}

	free(L);
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

	scanf("%d %d\n", &x, &y);

	// Alocando memória da tela
	tela = (char **) malloc (sizeof(char *) * x);
	for(i = 0; i < x; i++)
		tela[i] = (char *) malloc (sizeof(char) * (y + 1));

	// Recebendo o conteúdo da tela
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++)
			scanf("%c", &tela[i][j]);
		tela[i][y] = '\0';
		scanf("%c", &lixo);
	}

	// Recebendo a posição e a tinta a ser preenchida na tela
	while(scanf("%d %d %c\n", &coordX, &coordY, &tinta) != EOF){
		// Cria a lista contendo as posições a serem pintadas e pinta a tela
		geraLista(tela, tinta, coordX, coordY, x, y);

		// Imprime a tela colorida
		imprimeTela(tela, x);
	}

	// Liberando dados alocados
	for(i = 0; i < x; i++)
		free(tela[i]);
	free(tela);

	return 0;
}
