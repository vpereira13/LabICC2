/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 11
 * Exercício 1 - Jogando Bolas
 * Victor Luiz da Silva Mariano Pereira 8602444
 */

#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct arvore Arvore;
Arvore *criaArvore(int, int);
void esvaziaArvore(Arvore *);
void imprimeArvore(Arvore *);
int jogaBola(Arvore *);

#endif