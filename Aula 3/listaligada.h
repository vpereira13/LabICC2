/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 3
 * Exercício 1 - Cálculo da Derivada e Reta Tangente
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
 * Função que imprime uma lista (equação)
 * @param L lista a ser impressa
 */
void imprimeLista (Lista *);

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

/*
 * CABEÇALHOS DAS FUNÇÕES REFERENTES AOS ITENS
 */

 /**
  * Função que cria um item, alocando espaço e colocando os valores dados
  * @param  coeficiente valor do coeficiente
  * @param  expoente    valor do expoente
  * @return             item alocado e com conteúdo
  */
Item *criaItem(long int, int);

/**
 * Função que retorna um item que está numa dada posição
 * @param  L      lista a ser analisada
 * @param  indice índice do item a ser encontrado
 * @return        item que está na posição dada
 */
Item *naPosicao(Lista *, int);

/**
 * Função que imprime um dado do tipo item da forma certa para cada tipo de
 * parte da função
 * @param I        item a ser impresso
 * @param primeiro parametro auxiliar para dizer se é o primeiro item de uma
 * função, pois se for e o valor do coeficiente for positivo, ele não pode
 * conter o sinal
 */
void imprimeItem(Item *, int);

/**
 * Função que retorna o valor do coeficiente de um item
 * @param  I item a ser analisado
 * @return   valor do coeficiente do item
 */
long int coeficienteItem(Item *);

/**
 * Função que retorna o valor do expoente de um item
 * @param  I item a ser analisado
 * @return   valor do expoente do item
 */
int expoenteItem(Item *);

#endif