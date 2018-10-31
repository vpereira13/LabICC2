/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 9
 * Exercício 1 - Imagens
 * Victor Luiz da Silva Mariano Pereira	8602444
 */
#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct arvore Arvore;

Arvore *inicia_arvore();
void cria_arvore(Arvore *, char *, int *);
void mistura_arvores(Arvore *, Arvore *);
void contagem(Arvore *, int *, int);
void imprime_arvore(Arvore *);

#endif