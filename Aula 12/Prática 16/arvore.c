/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 12
 * Exercício 2 - Editor de Árvore AVL II
 * Victor Luiz da Silva Mariano Pereira    8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore{
    int valor;
    int altura;
    struct arvore *esquerda;
    struct arvore *direita;
};

int maior(int a, int b){
    return a > b ? a : b;
}

Arvore *criaArvore(){
    Arvore *A = (Arvore *) malloc(sizeof(Arvore));

    A->direita = NULL;
    A->esquerda = NULL;

    return A;
}

int alturaArvore(Arvore *A){
    return A ? A->altura : -1;
}

int fatorBalanceamento(Arvore *A){
    return abs(alturaArvore(A->esquerda) - alturaArvore(A->direita));
}

void rotacaoDireita(Arvore *A){
    Arvore *Aux = NULL;

    Aux = A->esquerda;
    A->esquerda = Aux->direita;
    Aux->direita = A;
    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;

    Aux->altura = maior(alturaArvore(Aux->esquerda), A->altura) + 1;

    A = Aux;
}

void rotacaoEsquerda(Arvore *A){
    Arvore *Aux = NULL;

    Aux = A->direita;
    A->direita = Aux->esquerda;
    Aux->esquerda = A;
    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;

    Aux->altura = maior(alturaArvore(Aux->direita), A->altura) + 1;

    A = Aux;
}

void rotacaoDireitaEsquerda(Arvore *A){
    rotacaoEsquerda(A->direita);
    rotacaoDireita(A);
}
void rotacaoEsquerdaDireita(Arvore *A){
    rotacaoDireita(A->esquerda);
    rotacaoEsquerda(A);
}

int insere(Arvore *A, int valor){
    int resultado;

    Arvore *novo = NULL;
    if(!A){
        novo = criaArvore();
        if(!novo)
            return 0;

        novo->valor = valor;
        novo->altura = 0;
        A = novo;

        return 1;
    }
    else{
        novo = A;
        if(valor < novo->valor){
            if((resultado = insere(novo->esquerda, valor)) == 1)
                if(fatorBalanceamento(novo) > 1){
                    if(valor < A->esquerda->valor)
                        rotacaoEsquerda(A);
                    else
                        rotacaoEsquerdaDireita(A);
                }
        }
        else if(valor > novo->valor){
            if((resultado = insere(novo->direita, valor)) == 1)
                if(fatorBalanceamento(novo) > 1){
                    if(valor > A->direita->valor)
                        rotacaoDireita(A);
                    else
                        rotacaoDireitaEsquerda(A);
                }
        }
        else
            return 0;
    }
    novo->altura = maior(alturaArvore(novo->esquerda), alturaArvore(novo->direita)) +1;

    return resultado;
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
void imprimeLargura(Arvore *A){
    if(!A)
        return;
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
