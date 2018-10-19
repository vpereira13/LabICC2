/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 8
 * Exercício 1 - Cartas
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#ifndef _FILA_H_
#define _FILA_H_

typedef struct fila Fila;
typedef struct item Item;
typedef struct no No;

/**
 * Função que aloca memória para uma fila e inicializa ela, com tamanho zero e
 * primeiro item sendo nulo
 * @return uma fila alocada e com tamanho zero
 */
Fila *criaFila();

/**
 * Função que adiciona um item no final da fila
 * @param F fila que vai receber o item
 * @param I item a ser inserido na fila
 */
void insere(Fila *, Item *);

/**
 * Função para imprimir a fila
 * @param F fila a ser impressa
 */
void imprimeFila(Fila *);

/**
 * Função que verifica se a fila está vazia ou não
 * @param  F fila a ser analisada
 * @return   retorna se a fila está vazia ou não
 */
char estaVazia(Fila *);

/**
 * Função que retorna o tamanho da fila
 * @param  F fila a ser analisada
 * @return   tamanho da fila
 */
int tamanhoFila(Fila *);

/**
 * Função para esvaziar uma fila
 * @param F fila a ser esvaziada
 */
void esvaziaFila(Fila *);

/**
 * Função que retira o primeiro item da fila e retorna
 * @param  F fila a ter o item retirado
 * @return   primeiro item da fila
 */
Item *retira(Fila *);

/**
 * Função para iniciar um item, só alocando memória para um item
 * @return espaço de memória alocado para um item
 */
Item *iniciaItem();

/**
 * Função que cria um item já inicializando o valor dele
 * @param  valor valor do item criado
 * @return       item alocado e com conteúdo
 */
Item *criaItem(int);

/**
 * Função que imprime o dado de um tipo item
 * @param I item a ser impresso
 */
void imprimeItem(Item *);

/**
 * Função que retorna o valor de um item
 * @param  I      item a ser analisado
 * @return        valor do item
 */
int valor(Item *);

#endif