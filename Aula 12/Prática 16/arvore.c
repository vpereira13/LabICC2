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

/**
 * Função para verificar qual o maior entre dois números
 *
 * @param  a: Primeiro valor a ser verificado
 * @param  b: Segundo valor a ser verificado
 *
 * @retval Maior entre os dois valores
 */
int maior(int a, int b){
    return a > b ? a : b;
}

/**
 * Função para alocar espaço para uma árvore, com os valores iniciais já
 * setados, e retorna um ponteiro para o endereço de memória da mesma
 *
 * @retval ponteiro para uma árvore
 */
Arvore *criaArvore(int valor){
    Arvore *A = (Arvore *) malloc(sizeof(Arvore));

    A->valor = valor;
    A->altura = 0;
    A->direita = NULL;
    A->esquerda = NULL;

    return A;
}

/**
 * Função que retorna a altura de uma árvore
 *
 * @param  *A: Árvore a ser analisada
 * @retval altura da árvore, se ela não existir, retorna -1
 */
int alturaArvore(Arvore *A){
    return A ? A->altura : -1;
}

/**
 * Função que calcula o fator de balanceamento de uma árvore
 *
 * @param  *A: Árvore a ser analisada
 * @retval fator de balanceamento
 */
int fatorBalanceamento(Arvore *A){
    return abs(alturaArvore(A->esquerda) - alturaArvore(A->direita));
}

/**
 * Função auxiliar que faz uma rotação simples para a direita
 *
 * @param  *A: árvore que tem que ser rotacionada
 */
void rotacaoDireita(Arvore *A){
    Arvore *Aux = NULL;

    Aux = A->esquerda;
    A->esquerda = Aux->direita;
    Aux->direita = A;
    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;

    Aux->altura = maior(alturaArvore(Aux->esquerda), A->altura) + 1;

    A = Aux;
}

/**
 * Função auxiliar que faz uma rotação simples para a esquerda
 *
 * @param  *A: árvore que tem que ser rotacionada
 */
void rotacaoEsquerda(Arvore *A){
    Arvore *Aux = NULL;

    Aux = A->direita;
    A->direita = Aux->esquerda;
    Aux->esquerda = A;
    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;

    Aux->altura = maior(alturaArvore(Aux->direita), A->altura) + 1;

    A = Aux;
}

/**
 * Função auxiliar que faz uma rotação dupla, primeiro para a esquerda no filho
 * da direita e depois uma a direita no nó principal
 *
 * @param  *A: árvore que tem que ser rotacionada
 */
void rotacaoDireitaEsquerda(Arvore *A){
    rotacaoEsquerda(A->direita);
    rotacaoDireita(A);
}

/**
 * Função auxiliar que faz uma rotação dupla, primeiro para a direita no filho
 * da esquerda e depois uma a esquerda no nó principal
 *
 * @param  *A: árvore que tem que ser rotacionada
 */
void rotacaoEsquerdaDireita(Arvore *A){
    rotacaoDireita(A->esquerda);
    rotacaoEsquerda(A);
}

/**
 * Função que insere um valor em uma árvore, já aplicando rotações se caso
 * necessário
 *
 * @param  *A: árvore a ser inserido o valor
 * @param  valor: valor a ser inserido na árvore
 * @retval 0 - se falha
 *         1 - se sucesso
 */
Arvore *insere(Arvore *A, int valor, int *erro){
    if(!A)
        return criaArvore(valor);
    else{
        if(valor < A->valor){
            A->esquerda = insere(A->esquerda, valor, erro);
            //if(fatorBalanceamento(A) > 1){
            //    if(valor < A->esquerda->valor)
            //        rotacaoEsquerda(A);
            //    else
            //        rotacaoEsquerdaDireita(A);
            //}
        }
        else if(valor > A->valor){
            A-> direita = insere(A->direita, valor, erro);
            //if(fatorBalanceamento(A) > 1){
            //    if(valor > A->direita->valor)
            //        rotacaoDireita(A);
            //    else
            //        rotacaoDireitaEsquerda(A);
            //}
        }
        else{
            *erro = 1;
            return A;
        }
    }
    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;

    return A;
}

/**
 * Função para imprimir uma árvore de forma IN ordem
 *
 * @param  *A: árvore a ser impressa
 */
void imprimeIN(Arvore *A){
    if(!A)
        return;
    else{
        imprimeIN(A->esquerda);
        printf(" %d", A->valor);
        imprimeIN(A->direita);
    }
}

/**
 * Função para imprimir uma árvore de forma PRE ordem
 *
 * @param  *A: árvore a ser impressa
 */
void imprimePRE(Arvore *A){
    if(!A)
        return;
    else{
        printf(" %d", A->valor);
        imprimeIN(A->esquerda);
        imprimeIN(A->direita);
    }
}

/**
 * Função para imprimir uma árvore de forma POS ordem
 *
 * @param  *A: árvore a ser impressa
 */
void imprimePOS(Arvore *A){
    if(!A)
        return;
    else{
        imprimeIN(A->esquerda);
        imprimeIN(A->direita);
        printf(" %d", A->valor);
    }
}

/**
 * Função auxiliar que imprime os níveis de uma árvore
 *
 * @param  *A: árvore a ser impressa
 * @param  nivel: qual nível está sendo analisado
 */
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

/**
 * Função para imprimir uma árvore de forma de largura
 *
 * @param  *A: árvore a ser impressa
 */
void imprimeLargura(Arvore *A){
    int i;

    for(i = 0; i < A->altura; i++)
        imprimeNivel(A, i);
}

/**
 * Função para imprimir uma árvore de todas as formas
 *
 * @param  *A: árvore a ser impressa
 */
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