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
 * Função auxiliar para realizar uma troca de dois elemetos de um vetor de
 * ATLETAS
 * @param vetor vetor que contém os elementos a serem trocados
 * @param i     elemento a ser trocado
 * @param j     elemento a ser trocado
 */
void troca(ATLETA **vetor, int i, int j){
	ATLETA *aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

/**
 * Função responsável pela volta do merge sort, fase de merge
 * @param vetor  vetor a ser ordenado
 * @param inicio indice do inicio do vetor (esquerda)
 * @param meio   indice do meio do vetor
 * @param fim    indice do final do vetor
 * @param opcao  por qual item que será ordenado, pelo “ID” ou pelo “NAME”
 */
void merge(ATLETA **vetor, int inicio, int meio, int fim, char *opcao){
	int i;
	int j;
	int k;
	int n1;
	int n2;

	n1 = meio - inicio + 1;
	n2 =  fim - meio;

	// Criando vetores auxiliares
	ATLETA **auxEsquerda;
	ATLETA **auxDireita;
	auxEsquerda = (ATLETA **) malloc(sizeof(ATLETA *) * n1);
	auxDireita = (ATLETA **) malloc(sizeof(ATLETA *) * n2);

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
		if(!strcmp(opcao, "ID")){
			if (auxEsquerda[i]->id <= auxDireita[j]->id)
				vetor[k] = auxEsquerda[i++];
			else
				vetor[k] = auxDireita[j++];
		}
		else if(!strcmp(opcao, "NAME")){
			if (strcmp(auxEsquerda[i]->nome, auxDireita[j]->nome) < 1)
				vetor[k] = auxEsquerda[i++];
			else
				vetor[k] = auxDireita[j++];
		}
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
 * @param vetor vetor a ser ordenado
 * @param inicio      indice inicial (o da esquerda)
 * @param fim         indice final (o da direita)
 * @param opcao       opcao de ordenação por “NAME” ou por “ID”
 * @param maximo      número máximo de merges que o merge sort pode fazer
 * @param quantidade  quantidade de merges que foram feitos até o momento
 */
void mergeSort(ATLETA **vetor, int inicio, int fim, char *opcao, int maximo, int *quantidade){
	int meio;
	if (inicio < fim){
		meio = (inicio + fim) /2;

		// Chamadas recursivas para as duas metades
		mergeSort(vetor, inicio, meio, opcao, maximo, quantidade);
		mergeSort(vetor, meio+1, fim, opcao, maximo, quantidade);

		// Verificação da quantidade máxima de merges
		if(*quantidade <= maximo){
			merge(vetor, inicio, meio, fim, opcao);
			(*quantidade)++;
		}
	}
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
	int maximo;
	int quantidade = 0;
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
	scanf("%s %d", comparacao, &maximo);

	// Faz a “ordenação”
	mergeSort(vetor, 0, i-1, comparacao, maximo, &quantidade);

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
