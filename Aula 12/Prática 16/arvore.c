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
    if(!A)
        return 0;
    return alturaArvore(A->esquerda) - alturaArvore(A->direita);
}

/**
 * Função que faz uma rotação simples a direita
 *
 * @param  *A: árvore a ser rotacionada
 * @retval ponteiro para uma árvore já rotacionada
 */
Arvore *rotacaoDireita(Arvore *A){
    Arvore *Aux = NULL;
    Arvore *Novo = NULL;

    Novo = A->esquerda;
    Aux = Novo->direita;

    Novo->direita = A;
    A->esquerda = Aux;

    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;
    Novo->altura = maior(alturaArvore(Novo->esquerda), alturaArvore(Novo->direita)) + 1;

    return Novo;
}

/**
 * Função que faz uma rotação simples a esquerda
 *
 * @param  *A: árvore a ser rotacionada
 * @retval ponteiro para uma árvore já rotacionada
 */
Arvore *rotacaoEsquerda(Arvore *A){
    Arvore *Aux = NULL;
    Arvore *Novo = NULL;

    Novo = A->direita;
    Aux = Novo->esquerda;

    Novo->esquerda = A;
    A->direita = Aux;

    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;
    Novo->altura = maior(alturaArvore(Novo->esquerda), alturaArvore(Novo->direita)) + 1;

    return Novo;
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
        if(valor < A->valor)
            A->esquerda = insere(A->esquerda, valor, erro);
        else if(valor > A->valor)
            A-> direita = insere(A->direita, valor, erro);
        else{
            *erro = 1;
            return A;
        }
    }

    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;

    if(fatorBalanceamento(A) > 1){
        if(A->esquerda->valor > valor)
            return rotacaoDireita(A);
        else if(A->esquerda->valor < valor){
            A->esquerda =  rotacaoEsquerda(A->esquerda);
            return rotacaoDireita(A);
        }
    }

    if(fatorBalanceamento(A) < -1){
        if(A->direita->valor < valor)
            return rotacaoEsquerda(A);
        else if(A->direita->valor > valor){
            A->direita = rotacaoDireita(A->direita);
            return rotacaoEsquerda(A);
        }
    }

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
        printf("%d ", A->valor);
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
        printf("%d ", A->valor);
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
        printf("%d ", A->valor);
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
        printf("%d ", A->valor);
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

    for(i = 1; i <= (A->altura + 1); i++)
        imprimeNivel(A, i);
}

/**
 * Função para imprimir uma árvore de todas as formas
 *
 * @param  *A: árvore a ser impressa
 */
void imprimeTodos(Arvore *A){
    printf("InOrdem: ");
    imprimeIN(A);
    printf("\n");

    printf("PreOrdem: ");
    imprimePRE(A);
    printf("\n");

    printf("PosOrdem: ");
    imprimePOS(A);
    printf("\n");

    printf("Largura: ");
    imprimeLargura(A);
    printf("\n");
}

/**
 * Função que esvazia uma árvore, liberando todo o seu conteúdo
 *
 * @param  *A: árvore a ser liberada
 */
void esvazia(Arvore *A){
    if(A){
        esvazia(A->esquerda);
        esvazia(A->direita);
        free(A);
    }
}

/**
 * Função que faz uma busca de um valor em uma árvore
 *
 * @param  *A: árvore a ser analisada
 * @param  valor: valor do item a ser encontrado
 * @retval 0 - se não encontrar o valor
 *         1 - se encontrar o valor
 */
int busca(Arvore *A, int valor){
    if(!A)
        return 0;
    else
        return A->valor == valor ? 1 : (A->valor > valor ? busca(A->esquerda, valor) : busca(A->direita, valor));
}

/**
 * Função que encontra a sub árvore com o menor valor
 *
 * @param  *A: árvore a ser analisada
 * @retval árvore com o menor valor
 */
Arvore *menorValor(Arvore *A){
    Arvore *Aux = A;

    while(Aux->esquerda)
        Aux = Aux->esquerda;

    return Aux;
}

/**
 * Função que remove um item, se ele existir e rebalanceia a árvore, se
 * necessário
 *
 * @param  *A: árvore analisada e removida o item
 * @param  valor: valor a ser removido
 * @param  *erro: variável para verificar se o item foi removido com sucesso ou
 * não
 * @retval nova árvore balanceada e sem o item removido
 */
Arvore *removeItem(Arvore *A, int valor, int *erro){
    Arvore *Aux = NULL;

    if(!A){
        *erro = 1;
        return A;
    }

    if(A->valor > valor)
        A->esquerda = removeItem(A->esquerda, valor, erro);
    else if(A->valor < valor)
        A->direita = removeItem(A->direita, valor, erro);
    else{
        if(!A->direita || !A->esquerda){
            Aux = A->direita ? A->direita : A->esquerda;

            if(!Aux){
                Aux = A;
                A = NULL;
            }
            else
                *A = *Aux;

            free(Aux);
        }
        else{
            Aux = menorValor(A->direita);
            A->valor = Aux->valor;
            A->direita = removeItem(A->direita, Aux->valor, erro);
        }
    }

    if (!A)
      return A;

    A->altura = maior(alturaArvore(A->esquerda), alturaArvore(A->direita)) + 1;

    if (fatorBalanceamento(A) > 1){
        if(fatorBalanceamento(A->esquerda) >= 0)
            return rotacaoDireita(A);
        else{
            A->esquerda = rotacaoEsquerda(A->esquerda);
            return rotacaoDireita(A);
        }
    }

    if (fatorBalanceamento(A) < -1){
        if (fatorBalanceamento(A->direita) <= 0)
            return rotacaoEsquerda(A);
        else{
            A->direita = rotacaoDireita(A->direita);
            return rotacaoEsquerda(A);
        }
    }

    return A;
}