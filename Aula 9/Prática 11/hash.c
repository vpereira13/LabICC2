/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 9
 * Exercício 2 - Tabela Hash <>
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include "hash.h"
#include <stdlib.h>
#include <string.h>

struct no{
	char *chave;
};

struct hash{
	int tamanho;
	No *vetor;
};

/**
 * Função que calcula qual o valor de uma dada string
 * @param  string string a ser calculada
 * @return        valor correspondente a string
 */
int valorString(char *string){
	int i;
	int valor = 0;
	int tamanho = strlen(string);

	for(i = 0; i < tamanho; i++)
		valor += (int) string[i] * (i + 1);

	return valor;
}

/**
 * Função responsável por criar a tabela hash, alocando memória e criando com
 * o tamanho pré definido
 * @param  tamanho tamanho da tabela hash
 * @return         ponteiro para uma tabela hash
 */
Hash *cria_hash(int tamanho){
	int i;
	Hash *H = (Hash *) malloc(sizeof(Hash));

	H->tamanho = tamanho;
	H->vetor = (No *) malloc(sizeof(No) * tamanho);
	for(i = 0; i < tamanho ; i++)
		H->vetor[i].chave = NULL;

	return H;
}

/**
 * Função responsável por inserir um valor na tabela hash
 * @param H      tabela hash
 * @param string string a ser inserida
 */
void insere(Hash *H, char *string){
	int posicao = valorString(string) % H->tamanho;

	while(H->vetor[posicao].chave != NULL)
		posicao = (posicao + 1) % H->tamanho;

	H->vetor[posicao].chave = (char *) malloc(sizeof(char) * (strlen(string) + 1));
	strcpy(H->vetor[posicao].chave, string);
}

/**
 * Função que remove um item da tabela hash, se encontrar
 * @param H      tabela hash
 * @param string string a ser removida
 */
void remove_item(Hash *H, char *string){
	int contador = 0;
	int posicao = valorString(string) % H->tamanho;

	while(strcmp(H->vetor[posicao].chave, string)){
		posicao = (posicao + 1) % H->tamanho;
		if(contador++ > H->tamanho)
			return;
	}

	free(H->vetor[posicao].chave);
}

/**
 * Função que procura na tabela hash uma dada string
 * @param  H      tabela hash a ser analisada
 * @param  string string a ser buscada
 * @return        0 - não achou; 1 - achou
 */
int busca(Hash *H, char *string){
	int contador = 0;
	int posicao = valorString(string) % H->tamanho;

	while(H->vetor[posicao].chave == NULL || strcmp(H->vetor[posicao].chave, string)){
		posicao = (posicao + 1) % H->tamanho;
		contador++;
		if(contador > H->tamanho - 1)
			return 0;
	}

	return 1;
}

/**
 * Função para limpar a tabela hash e liberar toda a memória (ainda não está
 * funcionando direito)
 * @param H tabela hash a ser limpa
 */
void esvazia_hash(Hash *H){
	int i;

	for(i = 0; i < H->tamanho; i++)
		if(H->vetor[i].chave != NULL)
			free(H->vetor[i].chave);
	free(H->vetor);
}