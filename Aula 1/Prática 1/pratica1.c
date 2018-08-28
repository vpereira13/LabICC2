/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 1
 * Exercício 1 - A raposa e o coelho
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definições para facilitar
#define NAO "O coelho nao pode escapar."
#define PODE "O coelho pode escapar pelo buraco"
#define X 0
#define Y 1

// Pode ser mais facil a visualização utilizando a estrutura de coordenada
/*
typedef struct{
	float x;
	float y;
} COORDENADA;
*/

/**
 * Função para calcular a distância euclidiana entre dois pontos (animal e buraco)
 * @param  xanimal coordenada x do animal
 * @param  yanimal coordenada y do animal
 * @param  xburaco coordenada x do buraco
 * @param  yburaco coordenada y do buraco
 * @return         distância euclidiana entre o animal e o buraco
 */
double calculaDistancia(float xanimal, float yanimal, float xburaco, float yburaco){
	return sqrt(pow((xanimal - xburaco), 2) + pow((yanimal - yburaco), 2));
}

/**
 * Função para verificar se o coelho consegue escapar da raposa
 * @param  xcoelho  coordenada x do coelho
 * @param  ycoelho  coordenada y do coelho
 * @param  xraposa  coordenada x da raposa
 * @param  yraposa  coordenada y da raposa
 * @param  nburacos numero de buracos
 * @param  buracos  vetor de buracos (coordenadas x e y)
 * @return          retorna o índice do buraco ou -1 se caso o coelho não
 *                  conseguir escapar
 */
int verificaChance(float xcoelho, float ycoelho, float xraposa, float yraposa, int nburacos, float **buracos){
	int i;

	for (i = 0; i < nburacos; i++)
		// Se distância do coelho > 2* distância da raposa, ele consegue escapar
		if (calculaDistancia(xcoelho, ycoelho, buracos[i][X], buracos[i][Y]) < 0.5*calculaDistancia(xraposa, yraposa, buracos[i][X], buracos[i][Y]))
			return i;
	return -1;
}

int main(int argc, char *argv[]) {
	int i;
	int rota;
	int nburacos;
	float xcoelho;
	float ycoelho;
	float xraposa;
	float yraposa;

	float **buracos;

	scanf("%d", &nburacos);
	scanf("%f", &xcoelho);
	scanf("%f", &ycoelho);
	scanf("%f", &xraposa);
	scanf("%f", &yraposa);

	// Alocando espaços para os
	buracos = (float **) malloc(nburacos * sizeof(float *));
	for (i = 0; i < nburacos; i++)
		buracos[i] = (float *) malloc(2 * sizeof(float));

	// Coletando coordenadas do(s) buraco(s)
	for (i = 0; i < nburacos; i++ )
		scanf("%f %f\n", &buracos[i][X], &buracos[i][Y]);

	// Recebe o índice do buraco que o coelho vai escapar ou -1 se não conseguir
	rota = verificaChance(xcoelho, ycoelho, xraposa, yraposa, nburacos, buracos);

	rota < 0 ? printf("%s\n", NAO) : printf("%s (%.3f,%.3f).", PODE, buracos[rota][X], buracos[rota][Y]);

	// Liberando memória
	for (i = 0; i < nburacos; i++)
		free(buracos[i]);
	free(buracos);

	return 0;
}