/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 9
 * Exercício 2 - Tabela Hash <>
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#ifndef _HASH_H_
#define _HASH_H_

typedef struct no No;
typedef struct hash Hash;

Hash *cria_hash(int);
void insere(Hash *, char *);
void remove_item(Hash *, char *);
int busca(Hash *, char *);
void esvazia_hash(Hash *);

#endif