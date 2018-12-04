/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 10
 * Exercício 1 - Editor de Árvore Binária de Busca
 * Victor Luiz da Silva Mariano Pereira    8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore{
    int valor;
    struct arvore *direita;
    struct arvore *esquerda;
};

Arvore *criaArvore(int valor){
    Arvore *A = (Arvore *) malloc(sizeof(Arvore));

    A->valor = valor;
    A->direita = NULL;
    A->esquerda = NULL;

    return A;
}

Arvore *insereItem(Arvore *A, int valor, int *erro){
    if(!A)
        return criaArvore(valor);
    if(A->valor > valor)
        A->esquerda = insereItem(A->esquerda, valor, erro);
    else if(A->valor < valor)
        A->direita = insereItem(A->direita, valor, erro);
    else
        *erro = 1;
    return A;
}

void removeItem(Arvore *A, int valor){

}

int buscaItem(Arvore *A, int valor){
    if(!A)
        return 0;
    else{
        if(A->valor == valor)
            return 1;
        return (valor > A->valor ? buscaItem(A->direita, valor) : buscaItem(A->esquerda, valor));
    }
}

void imprimeIN(Arvore *A){
    if(!A)
        return;
    else{
        imprimeIN(A->esquerda);
        printf(" %d", A->valor);
        imprimeIN(A->direita);
    }
}

void imprimePRE(Arvore *A){
    if(!A)
        return;
    else{
        printf(" %d", A->valor);
        imprimeIN(A->esquerda);
        imprimeIN(A->direita);
    }
}

void imprimePOS(Arvore *A){
    if(!A)
        return;
    else{
        imprimeIN(A->esquerda);
        imprimeIN(A->direita);
        printf(" %d", A->valor);
    }
}

int alturaArvore(Arvore *A){
    int direita;
    int esquerda;

    if(!A)
        return 0;
    else{
        direita = alturaArvore(A->direita);
        esquerda = alturaArvore(A->esquerda);
        return esquerda > direita ? esquerda + 1 : direita + 1;
    }
}

void imprimeNivel(Arvore *A, int nivel){
    if(!A)
        return;
    if(nivel == 1)
        printf(" %d", A->valor);
    else if(nivel > 1){
        imprimeNivel(A->esquerda, nivel - 1);
        imprimeNivel(A->direita, nivel - 1);
    }
}

void imprimeLargura(Arvore *A){
    int i;
    int altura;

    altura = alturaArvore(A);

    for(i = 0; i < altura; i++)
        imprimeNivel(A, i);
}

void imprimeTodos(Arvore *A){
    printf("InOrdem:");
    imprimeIN(A);
    printf("\n");

    printf("PreOrdem:");
    imprimePRE(A);
    printf("\n");

    printf("PosOrdem:");
    imprimePOS(A);
    printf("\n");

    printf("Largura:");
    imprimeLargura(A);
    printf("\n");
}

void esvazia(Arvore *A){
    if(A){
        esvazia(A->esquerda);
        esvazia(A->direita);
        free(A);
    }
}
