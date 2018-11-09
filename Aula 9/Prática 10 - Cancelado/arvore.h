/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 9
 * Exercício 1 - Editor de Árvore Binária de Busca
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct arvore Arvore;

void insere(Arvore *, int);
void remove(Arvore *, int);
int busca(Arvore *, int);
void imprimeIN(Arvore *);
void imprimePRE(Arvore *);
void imprimePOS(Arvore *);
void imprimeLargura(Arvore *);
void imprimeTodos(Arvore *);

#endif