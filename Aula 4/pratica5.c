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
#include <string.h>

#define TAM 100

/**
 * Estrutura do tipo atleta, contendo a equipe pela qual ele compete, o id dele
 * na competição e por ultimo o nome dele.
 */
typedef struct atleta{
	char *equipe;
	int id;
	char *nome;
}ATLETA;

/**
 * Função para comprar dois inteiros, feita para ser passada por parâmetro para
 * a função de ordenação merge sort
 * @param  a primeiro inteiro a ser comparado
 * @param  b segundo inteiro a ser comparado
 * @return   inteiro podendo ter os seguintes valores
 *                0 - se os dois forem iguais
 *              < 0 - se o primeiro for menor que o segundo
 *              > 0 - se o primeiro for maior que o segundo
 */
int inteiroCMP(const void *a, const void *b){
	return ((*(int*)a) - (*(int*)b));
}

/**
 * Função para comparar duas strings, feita para ser passada por parametro para
 * a função de ordenação merge sort
 * @param  a primeira string a ser comparada
 * @param  b segunda string a ser comparada
 * @return   inteiro podendo ter os seguintes valores
 *                0 - se as duas forem iguais
 *              < 0 - se a primeira for menor que a segunda
 *              > 0 - se a primeira for maior que a segunda
 */
int stringCMP(const void *a, const void *b){
	return (strcmp(((char*)a), ((char*)b)));
}

void merge(ATLETA **vetor, int inicio, int meio, int fim){
	int i;
	int j = inicio;
	int k = meio + 1;
	int l = 0;

	ATLETA **aux = (ATLETA **) malloc((fim-inicio + 1) * sizeof(ATLETA *));

	for(i = inicio; i <= fim; i++){
		if(j > meio)
			aux[l++] = vetor[k++];
		else if(k > fim)
			aux[l++] = vetor[j++];
		else if(strcmp(vetor[j]->nome, vetor[k]->nome) < 0)
			aux[l++] = vetor[j++];
		else
			aux[l++] = vetor[k++];
	}

	for(i = 0; i < l; i++)
		vetor[inicio++] = aux[j];
}

void mergeSort(ATLETA **vetor, int inicio, int fim){
	int meio = (inicio + fim) / 2;
	if (inicio < fim){
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
		merge(vetor, inicio, meio, fim);
	}
}

/**
 * Função que cria um ponteiro para a estrutura atleta, já colocando os valores
 * passados por parametro
 * @param  equipe string contendo a equipe do atleta
 * @param  id     inteiro contendo o id do atleta
 * @param  nome   string contendo o nome do atleta
 * @return        um ponteiro para uma estrutura do tipo atleta
 */
ATLETA *criaAtleta(char *equipe, int id, char *nome){
	ATLETA *a = (ATLETA *) malloc (sizeof(ATLETA));

	a->equipe = (char *) malloc (strlen(equipe) + 1);
	a->nome = (char *) malloc (strlen(nome) + 1);

	strcpy(a->equipe, equipe);
	strcpy(a->nome, nome);

	a->id = id;

	return a;
}

/**
 * Função responsável pela impressão do vetor da forma que o exercício solicita
 * @param vetor   vetor a ser impresso
 * @param tamanho tamanho do vetor a ser impresso
 */
void imprimeVetor(ATLETA **vetor, int tamanho){
	int i;
	for (i = 0; i < tamanho; i++)
		printf("%s %d %s\n",vetor[i]->equipe, vetor[i]->id, vetor[i]->nome);
}

/**
 * Função responsável por liberar o conteúdo de um vetor de atletas
 * @param vetor   vetor de atletas
 * @param tamanho tamanho do vetor a ser desalocado
 */
void liberaAtleta(ATLETA **vetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		free(vetor[i]->nome);
		free(vetor[i]->equipe);
		free(vetor[i]);
	}
}

int main (int argc, char *argv[]){
	int i = 0;
	int id;
	int quantidade;
	char *comparacao;
	char *linha;
	char *equipe;
	char *nome;
	ATLETA **vetor;

	// Alocando memória para as variáveis
	vetor = (ATLETA **) malloc (300 * sizeof(ATLETA *));
	equipe = (char *) malloc (8);
	nome = (char *) malloc (TAM);
	linha = (char *) malloc (TAM);
	comparacao = (char *) malloc (TAM);

	// Coletando informação de entrada
	scanf("%s", equipe);
	while(scanf("%d %[^\n]s", &id, nome) > 0)
		vetor[i++] = criaAtleta(equipe, id, nome);
	scanf("%s", equipe);
	while(scanf("%d %[^\n]s", &id, nome) > 0)
		vetor[i++] = criaAtleta(equipe, id, nome);
	scanf("%s %d", comparacao, &quantidade);

/*
	if(!strcmp(comparacao, "ID"))
		mergeSort(vetor, 0, i-1, inteiroCMP, &contador);
	else if(!strcmp(comparacao, "NAME"))
		mergeSort(vetor, 0, i-1, stringCMP, &contador);
*/

	// imprimindo a saída encontrada
	imprimeVetor(vetor, i);

	// Liberando memória alocada
	free(equipe);
	free(nome);
	free(linha);
	free(comparacao);
	liberaAtleta(vetor, i);
	free(vetor);

	return 0;
}
