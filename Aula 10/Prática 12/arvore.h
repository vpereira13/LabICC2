/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 10
 * Exercício 1 - Editor de Árvore Binária de Busca
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct arvore Arvore;

Arvore *criaArvore();
void insereItem(Arvore *, int);
void removeItem(Arvore *, int);
int buscaItem(Arvore *, int);
void imprimeIN(Arvore *);
void imprimePRE(Arvore *);
void imprimePOS(Arvore *);
void imprimeLargura(Arvore *);
void imprimeTodos(Arvore *);
void esvazia(Arvore *);

#endif