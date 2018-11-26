/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 11
 * Exercício 1 - Jogando Bolas
 * Victor Luiz da Silva Mariano Pereira 8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore{
    int valor;
    char flag;
    struct arvore *direita;
    struct arvore *esquerda;
};

Arvore *iniciaArvore(){
    Arvore *A = (Arvore *) malloc(sizeof(Arvore));
    A->flag = 'f';
    A->direita = NULL;
    A->esquerda = NULL;

    return A;
}

Arvore *criaArvore(int valor, int altura){
    Arvore *A = iniciaArvore();
    A->valor = valor;
    if(valor * 2 < (altura * altura) - 1){
        A->esquerda = criaArvore(valor * 2, altura);
        A->direita = criaArvore(valor * 2 + 1, altura);
    }

    return A;
}

void imprimeArvore(Arvore *A){
    if(A){
        printf("%d\t%c\n", A->valor, A->flag);
        imprimeArvore(A->esquerda);
        imprimeArvore(A->direita);
    }
}