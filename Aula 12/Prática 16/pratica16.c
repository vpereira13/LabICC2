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

int main (int argc, char *argv[]){
    int chave;
    int erro;
    char instrucao;
    Arvore *A = NULL;

    scanf("%c", &instrucao);

    while(instrucao != 'X'){
        erro = 0;
        switch(instrucao){
            // Inserção
            case 'I':
                scanf("%d\n", &chave);
                A = insere(A, chave, &erro);
                if(erro)
                    printf("Chave existente\n");
                break;

            // Remoção
            case 'D':
                scanf("%d\n", &chave);
                A = removeItem(A, chave, &erro);
                erro ? printf("Nao encontrado\n") : printf("%d\n", chave);
                break;

            // Busca
            case 'B':
                scanf("%d\n", &chave);
                busca(A, chave) ? printf("Encontrado\n") : printf("Não encontrado\n");
                break;

            // Impressão In Ordem
            case 'N':
                printf("InOrdem: ");
                imprimeIN(A);
                printf("\n");
                break;

            // Impressão Pre Ordem
            case 'E':
                printf("PreOrdem: ");
                imprimePRE(A);
                printf("\n");
                break;

            // Impressão Pos Ordem
            case 'O':
                printf("PosOrdem: ");
                imprimePOS(A);
                printf("\n");
                break;

            // Impressão Largura
            case 'L':
                printf("Largura: ");
                imprimeLargura(A);
                printf("\n");
                break;

            // Impressão de todas as formas
            case 'Y':
                imprimeTodos(A);
                break;

            default:
                break;
        }
        scanf("%c", &instrucao);
    }

    // Liberando memória
    esvazia(A);

    return 0;
}
