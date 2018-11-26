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

/**
 * Estrutura de árvore binária com o valor do nó, a flag dele se está como
 * 'v' ou 'f', um ponteiro para o filho da esquerda e um para o filho da
 * direita
 */
struct arvore{
    int valor;
    char flag;
    struct arvore *direita;
    struct arvore *esquerda;
};

/**
 * Função que aloca espaço na memória para a criação da árvore, setando seus
 * filhos como null e a flag como false
 *
 * @retval Um nó de uma árvore com seus filhos null e com a flag false
 */
Arvore *iniciaArvore(){
    Arvore *A = (Arvore *) malloc(sizeof(Arvore));
    A->flag = 'f';
    A->direita = NULL;
    A->esquerda = NULL;

    return A;
}

/**
 * Função que cria uma árvore binária completa dada uma altura, com os valores
 * dos nós e todas as flags setadas como falso
 *
 * @param  valor: Valor que o nó raiz dessa árvore vai receber
 * @param  altura: Altura da árvore final para limitar os filhos
 *
 * @retval Uma árvore completa limitada pela altura dada
 */
Arvore *criaArvore(int valor, int altura){
    Arvore *A = iniciaArvore();
    A->valor = valor;
    if(valor * 2 < (altura * altura) - 1){
        A->esquerda = criaArvore(valor * 2, altura);
        A->direita = criaArvore(valor * 2 + 1, altura);
    }

    return A;
}

/**
 * Função que imprime uma dada árvore da forma pré ordem
 *
 * @param  *A: Árvore a ser impressa
 */
void imprimeArvore(Arvore *A){
    if(A){
        printf("%d\t%c\n", A->valor, A->flag);
        imprimeArvore(A->esquerda);
        imprimeArvore(A->direita);
    }
}
