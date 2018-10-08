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

/**
 * Função de ordenação no estilo de inserção
 * @param vetor   vetor a ser ordenado
 * @param tamanho tamanho do vetor
 */
void insertionSort(int *vetor, int tamanho){
	int i;
	int j;
	int atual;

	for(i = 1; i < tamanho; i++){
		atual = vetor[i];
		j = i - 1;
		while(j > -1 && vetor[j] > atual){
			vetor[j + 1] = vetor[j];
			j--;
		}
		vetor[j+1] = atual;
	}
}

/**
 * Função responsável pela volta do merge sort, fase de merge
 * @param vetor  vetor a ser ordenado
 * @param inicio indice do inicio do vetor (esquerda)
 * @param meio   indice do meio do vetor
 * @param fim    indice do final do vetor
 */
void merge(int *vetor, int inicio, int meio, int fim){
	int i;
	int j;
	int k;
	int n1;
	int n2;

	n1 = meio - inicio + 1;
	n2 =  fim - meio;

	// Criando vetores auxiliares
	int *auxEsquerda;
	int *auxDireita;
	auxEsquerda = (int *) malloc(sizeof(int) * n1);
	auxDireita = (int *) malloc(sizeof(int) * n2);

	// Copiando conteúdo do vetor a ser ordenado para os auxiliares
	for (i = 0; i < n1; i++)
		auxEsquerda[i] = vetor[inicio + i];
	for (j = 0; j < n2; j++)
		auxDireita[j] = vetor[meio + 1+ j];

	// Fase de merge, voltando os vetores auxiliares para o vetor original
	i = 0;
	j = 0;
	k = inicio;
	while (i < n1 && j < n2){
		if (auxEsquerda[i] <= auxDireita[j])
			vetor[k] = auxEsquerda[i++];
		else
			vetor[k] = auxDireita[j++];
		k++;
	}

	// Caso de sobras, copia o resto dos elementos restantes no vetor original
	while (i < n1)
		vetor[k++] = auxEsquerda[i++];
	while (j < n2)
		vetor[k++] = auxDireita[j++];

	// Liberando memória
	free(auxEsquerda);
	free(auxDireita);
}

/**
 * Função de ordenação pelo método merge sort
 * @param vetor       vetor a ser ordenado
 * @param inicio      indice inicial (o da esquerda)
 * @param fim         indice final (o da direita)
 */
void mergeSort(int *vetor, int inicio, int fim){
	int meio;
	if (inicio < fim){
		meio = (inicio + fim) /2;

		// Chamadas recursivas para as duas metades
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, fim);

		// Verificação da quantidade máxima de merges
		merge(vetor, inicio, meio, fim);
	}
}

/**
 * Função auxiliar do quickSort(), que dado um vetor de inteiros, pega o ultimo
 * elemento como pivo e coloca ele no lugar correto do vetor. Além disso, a
 * função deixa os inteiros maiores que o pivo a direita dele e os menores
 * a esquerda
 * @param  vetor    vetor de inteiros a ser ordenado
 * @param  inicio   índice do início do vetor
 * @param  fim      índice do último elemento do vetor
 * @return          índice do inteiro que foi colocado no lugar certo
 */
int particao(int *vetor, int inicio, int fim){
	int i = (inicio - 1);
	int j;
	int pivo = vetor[fim];

	for (j = inicio; j <= fim - 1; j++)
		if (vetor[j] < pivo){
			i++;
			troca(vetor, i, j);
		}
	troca(vetor, i + 1, fim);
	return (i + 1);
}

/**
 * Função de ordenação  de inteiros quicksort
 * @param vetor    vetor de palavras
 * @param inicio   índice do início do vetor
 * @param fim      índice do fim do vetor
 */
void quickSort(int *vetor, int inicio, int fim){
	int i;
	if (inicio < fim){
		i = particao(vetor, inicio, fim);
		quickSort(vetor, inicio, i - 1);
		quickSort(vetor, i + 1, fim);
	}
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
	 * 	Heap sort
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
