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

int main(int argc, char const *argv[]){
    int altura;
    int nbolas;
    int final;
    Arvore *A = NULL;

    scanf("%d %d", &altura, &nbolas);

    A = criaArvore(1, altura);

    while(nbolas--)
        final = jogaBola(A);

    printf("%d\n", final);

    esvaziaArvore(A);
    free(A);

    return 0;
}
