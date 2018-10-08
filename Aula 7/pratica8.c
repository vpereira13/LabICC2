/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 7
 * Exercício 1 - Operações na ordenação
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS "INSERTIONSORT"
#define BS "BUBBLESORT"
#define MS "MERGESORT"
#define HS "HEAPSORT"
#define QS "QUICKSORT"

/**
 * Função que copia o conteúdo de um vetor de inteiros para outro vetor de
 * inteiros, utilizando a ‘memcpy’ para melhor desempenho
 * @param  origem  vetor de inteiros de origem
 * @param  tamanho tamanho do vetor de origem
 * @return         cópia do vetor de origem
 */
int *copia(int *origem, int tamanho){
	int *destino = (int *) malloc (sizeof(int) * tamanho);

	memcpy(destino, origem, tamanho * sizeof(int));

	return destino;
}

/**
 * Função auxiliar para trocar dois valores de um vetor
 * @param vetor vetor a ter os trocados
 * @param a     índice do primeiro valor
 * @param b     índice do segundo valor
 */
void troca(int *vetor, int a, int b){
	int temp;

	temp = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = temp;
}

/**
 * Função de ordenação no estilo de bolha
 * @param vetor   vetor a ser ordenado
 * @param tamanho tamanho do vetor
 */
void bubbleSort(int *vetor, int tamanho){
	int i;
	int j;

	for(i = 0; i < tamanho; i++)
		for(j = i+1; j < tamanho; j++)
			if(vetor[j] < vetor[i])
				troca(vetor, i, j);
}

int main (int argc, char *argv[]){
	int i;
	int n;
	int nAlgoritmos;
	int *dados = NULL;
	char **algoritmos = NULL;

	// Parte de coleta de dados
	scanf("%d %d", &nAlgoritmos, &n);

	algoritmos = (char **) malloc(sizeof(char *) * nAlgoritmos);
	for(i = 0; i < nAlgoritmos; i++)
		algoritmos[i] = (char *) malloc(sizeof(char) * 14);

	for(i = 0; i < nAlgoritmos; i++)
		scanf("%s", algoritmos[i]);

	dados = (int *) malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
		scanf("%d\n", &dados[i]);

	/**
	 * Implementar
	 * 	Merge sort
	 * 	Insertion sort
	 * 	Quick sort
	 * 	Heap sort
	 * 	Bubble sort
	 */

//	printf("Menor C: %s\n",);
//	printf("Maior C: %s\n",);
//	printf("Menor M: %s\n",);
//	printf("Maior M: %s\n",);

	// Liberando memória
	for(i = 0; i < nAlgoritmos; i++)
		free(algoritmos[i]);
	free(algoritmos);
	free(dados);

	return 0;
}
