/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 12
 * Exercício 2 - Editor de Árvore AVL II
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct arvore Arvore;

Arvore *criaArvore(int);
Arvore *insere(Arvore *, int, int *);
Arvore *removeItem(Arvore *, int, int *);

void imprimeIN(Arvore *);
void imprimePRE(Arvore *);
void imprimePOS(Arvore *);
void imprimeLargura(Arvore *);
void imprimeTodos(Arvore *);
int busca(Arvore *, int);
void esvazia(Arvore *);

#endif