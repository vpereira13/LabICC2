/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 6
 * Exercício 1 - Lista Backward
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#ifndef _LISTALIGADA_H_
#define _LISTALIGADA_H_

/*
 * TIPOS DE DADOS UTILIZADOS
 */

typedef struct item Item;
typedef struct no No;
typedef struct lista Lista;

/*
 * CABEÇALHOS DAS FUNÇÕES REFERENTES AS LISTAS
 */

/**
 * Função que alocamemória para uma lista e inicializa ela, com tamanho zero e o
 * primeiro item valendo NULL
 * @return uma lista alocada e com tamanho zero
 */
Lista *criaLista();

/**
 * Função que adiciona um item no inicio da lista
 * @param L lista a qual o item será inserido
 * @param I item a ser inserido
 */
void insereInicio(Lista *, Item *);

/**
 * Função que adiciona um item no final da lista
 * @param L lista a qual o item será inserido
 * @param I item a ser inserido
 */
void insereFim(Lista *, Item *);

/**
 * Função que imprime uma lista
 * @param L lista a ser impressa
 */
void imprimeLista(Lista *);

/**
 * Função que verifica se a lista dada está vazia ou não
 * @param  L lista a ser analisada
 * @return   retorna se está vazia ou não
 */
char estaVazia(Lista *);

/**
 * Função que retorna o tamanho de uma lista
 * @param  L lista a ser analisada
 * @return   tamanho da lista
 */
int tamanhoLista(Lista *);

/**
 * Função responsável por esvaziar a lista, liberando toda a memória alocada
 * @param L lista a ser esvaziada
 */
void esvaziaLista(Lista *);

/**
 * Função que remove o item dado um índice de uma dada lista
 * @param L      lista que terá o item removido
 * @param indice índice do item a ser removido
 */
void removeIndice(Lista *, int);

void removeItem(Lista *, int);

/**
 * Função que retira o primeiro elemento da lista e retorna elemento
 * @param  L    lista a ser retirado o primeiro elemento
 * @return      primeiro elemento da lista
 */
Item *pop(Lista *);

int tempoLista(Lista *);

/*
 * CABEÇALHOS DAS FUNÇÕES REFERENTES AOS ITENS
 */

/**
 * Função que cria um item, alocando espaço e colocando os valores dados
 * @param  X    valor da coordenada X
 * @param  X    valor da coordenada Y
 * @return      item alocado e com conteúdo
 */
Item *criaItem(int, int);

void criaEInsere(Lista *, int, int);

/**
 * Função que retorna um item que está numa dada posição
 * @param  L      lista a ser analisada
 * @param  indice índice do item a ser encontrado
 * @return        item que está na posição dada
 */
Item *naPosicao(Lista *, int);

/**
 * Função que retorna o valor da coordenada X de um item
 * @param  I item a ser analisado
 * @return   valor da coordenada X do item
 */
int chaveItem(Item *);

/**
 * Função que retorna o valor da coordenada Y de um item
 * @param  I item a ser analisado
 * @return   valor da coordenada Y do item
 */
int tempoItem(Item *);

/**
 * Função que imprime um dado do tipo item
 * @param I        item a ser impresso
 */
void imprimeItem(Item *);

/**
 * Função que verifica se um item está na lista ou não
 * @param  L lista a ser analisada
 * @param  I item a ser encontrado
 * @return   Resultado da procura
 *               0 - se não estiver na lista
 *               1 - se estiver na lista
 */
int estaNaLista(Lista *, Item *);

#endif