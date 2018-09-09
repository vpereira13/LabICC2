/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 3
 * Exercício 1 - Cálculo da Derivada e Reta Tangente
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listaligada.h"

/**
 * Função que encontra o resultado da função dada em um determinado ponto
 * @param  L lista contendo a função a ser analisada
 * @param  x ponto em que tem que ser calculada a função
 * @return   valor da função num dado ponto (tem que ser long int por causa dos
 *           casos de teste)
 */
long int calculaY(Lista *L, int x){
	int i;
	long int y;
	Item *item;

	for(i = 0, y = 0; i < tamanhoLista(L); i++){
		item = naPosicao(L, i);
		y += coeficienteItem(item) * pow(x, expoenteItem(item));
	}

	return y;
}

/**
 * Função que econtra a derivada de uma dada função, sempre sendo funções
 * polinomiais de uma variável
 * @param  L uma lista contendo a função polinomial a ser encontrada a derivada
 * @return   uma lista contendo a derivada da função polinomial dada
 */
Lista *encontraDerivada(Lista *L){
	int i;
	long int coeficiente;
	int expoente;
	Lista *flinha = criaLista();
	Item *item;
	Item *novo;

	for(i = 0; i < tamanhoLista(L); i++){
		item = naPosicao(L, i);
		coeficiente = coeficienteItem(item);
		expoente = expoenteItem(item);
		if(expoenteItem(item) > 0){
			novo = criaItem(coeficiente * expoente, expoente - 1);
			insereFim(flinha, novo);
		}
	}

	return flinha;
}

/**
 * Função que calcula a reta tangente em um ponto, usando a fórmula
 * y = m * x - m * x1 + y1
 * @param  x valor de x dado, na função x1
 * @param  y valor de y encontrado aplicando x1 na funçção dada
 * @param  m coeficiente angular da reta tangente, encontrado aplicando x1 na f'
 * @return   uma lista contendo a equação da reta tangente no ponto dado
 */
Lista *encontraTangente(int x, long int y, long int m){
	Lista *tangente = criaLista();

	Item *item = criaItem(m, 1);
	insereFim(tangente, item);
	item = criaItem(((-1) * m * x) + y, 0);
	insereFim(tangente, item);

	return tangente;
}

int main (int argc, char *argv[]){
	int x;
	long int y;
	long int m;
	int expoente;
	int coeficiente;
	Lista *f;
	Lista *flinha;
	Lista *tangente;

	Item *item;
	f = criaLista();

	// Recebendo valor de x
	scanf("%d\n", &x);

	// Recebendo os coeficientes, os expoentes e inserindo na lista
	// (AINDA PRECISA MELHORAR, NÃO COBRE O CASO 4)
	while(scanf("%d %d\n", &coeficiente, &expoente) != EOF){
		item = criaItem(coeficiente, expoente);
		insereFim(f, item);
	}

	// Cálculo de y
	y = calculaY(f, x);

	// Econtrando a derivada da funcao
	flinha = encontraDerivada(f);

	// Calculando o valor de m (basta calcular o valor de f'(x), em que x é o
	// ponto dado)
	m = calculaY(flinha, x);

	// Imprime a equação da derivada de f(x)
	printf("f'(x) = ");
	imprimeLista(flinha);

	// Econtra a equação da reta tangente
	tangente = encontraTangente(x, y, m);

	// Imprime a equação da reta tangente
	printf("g(x) = ");
	imprimeLista(tangente);

	// Liberando toda memória alocada
	esvaziaLista(f);
	free(f);
	esvaziaLista(flinha);
	free(flinha);
	esvaziaLista(tangente);
	free(tangente);


	return 0;
}