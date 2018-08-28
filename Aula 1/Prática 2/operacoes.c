/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 1
 * Exercício 2 - Operações Básicas
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include "operacoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Definindo tamanho máximo do inteiro (para multiplicação será necessário 2x)
#define ZERO 48 //ASCII

// Funções auxiliares para retornar o máximo ou o mínimo entre duas entradas
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

/**
 * Função para converter uma string em um vetor de inteiros
 * @param  string String que será convertida para um vetor de inteiro
 * @return        vetor de inteiro, sendo que o valor da primeira posição do
 *                vetor será a quantidade de dígitos que o “inteiro” tem. Se o
 *                inteiro for negativo, o valor da primeira posição será
 *                negativa também. Outro ponto, a ordem do vetor está invertida.
 *                Ex.: O número 6196420 ficará [7, 0, 2, 4, 6, 9, 1, 6]
 *                     O número -532 ficará [-3, 2, 3, 5]
 */
int *char2int(char *string){
	int i;
	int tamanho = strlen(string);
	int *inteiro = NULL;

	// Caso negativo
	if (string[0] == '-'){
		inteiro = (int *) malloc(tamanho * sizeof(int));
		inteiro[0] = - (tamanho - 1);
		for(i = 1; i < (abs(inteiro[0]) + 1); i++)
			inteiro[i] = ((int) string[(abs(inteiro[0]) + 1) - i] - ZERO);
	}
	// Caso positivo
	else{
		inteiro = (int *) malloc((tamanho + 1) * sizeof(int));
		inteiro[0] = tamanho;
		for(i = 1; i < (abs(inteiro[0]) + 1); i++)
			inteiro[i] = ((int) string[(abs(inteiro[0])) - i] - ZERO);
	}

	return inteiro;
}

/**
 * Função auxiliar para imprimir de forma correta um inteiro “grande”
 * @param inteiro vetor de inteiros
 */
void imprimeInteiro(int *inteiro){
	int i;

	// Caso negativo
	if(inteiro[0] < 0)
		printf("-");
	for(i = abs(inteiro[0]); i > 0; i--)
		printf("%d", inteiro[i]);

	printf("\n");
}

/**
 * Função auxiliar da biblioteca para dizer se um inteiro A é maior, menor ou
 * igual a um inteiro B
 * @param  A primeiro vetor de inteiros
 * @param  B segundo vetor de inteiros
 * @return   1 se A > B
 *          -1 se B > A
 *           0 se A = B
 */
int ehMaior(int *A, int *B){
	int i;
	// Número de dígitos de A > que de B
	if(A[0] > B[0])
		return 1;
	// Número de dígitos de B > que de A
	else if (A[0] < B[0])
		return -1;
	// Mesma quantidade de dígitos
	else
		for(i = A[A[0]]; i > 0; i--){
			// A > B
			if (A[i] > B[i])
				return 1;
			// B > A
			else if (A[i] < B[i])
				return -1;
		}
	// A = B
	return 0;
}

/**
 * Função que efetua a soma de dois vetores de inteiros não negativos
 * @param  A primeiro vetor de inteiros
 * @param  B segundo vetor de inteiros
 * @return   vetor de inteiros resultado da soma de A e B
 */
int *soma(int *A, int *B){
	int i;
	int soma;
	int excesso = 0;
	int *resultado = NULL;
	int maximo = MAX(A[0], B[0]);

	resultado = (int *) malloc((maximo + 2) * sizeof(int));
	resultado[0] = maximo;

	for(i = 1; i < maximo + 1; i++){
		// Caso tenha acabado o vetor A
		if(i > A[0])
			soma = B[i] + excesso;
		// Caso tenha acabado o vetor B
		else if(i > B[0])
			soma = A[i] + excesso;
		// Caso ainda tenha o vetor A e B
		else
			soma = A[i] + B[i] + excesso;

		// Calcula e atribui o valor da posição, fazendo mod 10
		resultado[i] = soma % 10;
		// Calcula o excedente
		excesso = soma / 10;
	}

	// Adicionando excesso no final, sendo ele diferente ou igual a zero
	resultado[maximo + 1] = excesso;
	// Caso diferente de zero, aumenta o "tamanho" do inteiro
	if (excesso != 0)
		resultado[0] = resultado[0] + 1;

	return resultado;
}

/**
 * Função que efetua a subtração de dois vetores de inteiros não negativos
 * @param  A primeiro vetor de inteiros
 * @param  B segundo vetor de inteiros
 * @return   vetor de inteiros resultado da subtração de A com B
 */
int *subtracao(int *A, int *B){
	int i;
	int maior;
	int subtracao;
	int empresta = 0;
	int *resultado = NULL;
	int maximo = MAX(A[0], B[0]);

	// Alocando espaço para o resultado, como é subtração, vai precisar de no máximo a mesma quantidade de casas que o maior número entre A e B
	resultado = (int *) malloc((maximo + 1) * sizeof(int));
	resultado[0] = maximo;

	maior = ehMaior(A, B);
	// Caso A > B
	if(maior == 1){
		for(i = 1; i < maximo + 1; i++){
			if(A[i] + empresta >= B[i]){
				subtracao = A[i] - B[i] + empresta;
				empresta = 0;
			}
			else{
				subtracao = 10 + A[i] - B[i] + empresta;
				empresta = -1;
			}
			resultado[i] = subtracao;
		}
	}
	// Caso B > A
	else if(maior == -1){
		for(i = 1; i < maximo + 1; i++){
			if(B[i] + empresta >= A[i]){
				subtracao = B[i] - A[i] + empresta;
				empresta = 0;
			}
			else{
				subtracao = 10 + B[i] - A[i] + empresta;
				empresta = -1;
			}
			resultado[i] = subtracao;
		}
		resultado[0] *= -1;
	}
	// Caso os dois números forem identicos, não precisa fazer conta
	else{
		resultado[0] = 1;
		resultado[1] = 0;
		return resultado;
	}

	// Atualizando tamanho do vetor resultado, necessário quando o vetor resultado fica com um monte de 0 a esquerda
	i = abs(resultado[0]);
	while (resultado[i] == 0) {
		// Caso o resultado for positivo
		if(resultado[0] < 0)
			resultado[0] += 1;
		// Caso for negativo
		else if(resultado[0] > 0)
			resultado[0] -= 1;
		i--;
	}

	return resultado;
}

/**
 * Função auxiliar da multiplicacao, ela multiplica um vetor de inteiros A por
 * um número escalar b e desloca k casas decimais
 * Ex.: 345 x 60 | A = [3, 5, 4, 3] b = 6 k = 1
 * @param  A vetor de inteiros
 * @param  b escalar que irá multiplicar o vetor de inteiros
 * @param  k potência de 10^k
 * @return   vetor de inteiros resultado da multiplicação de A x (b x 10^k)
 */
int *multiplicaIndividual(int *A, int b, int k){
	int i;
	int valor;
	int excesso = 0;
	int *resultado = NULL;

	// Usar calloc para poder deixar os k primeiros dígitos como zero
	resultado = (int *) calloc ((A[0] + k + 2), sizeof(int));
	resultado[0] = A[0] + k;

	for(i = k + 1; i < A[0] + k + 1; i++){
		valor = (A[i - k] * b) + excesso;
		resultado[i] = valor % 10;
		excesso = valor / 10;
	}

	resultado[A[0] + k + 1] = excesso;

	if(excesso != 0)
		resultado[0] += 1;

	return resultado;
}

/**
 * Função que calcula a multiplicação entre dois inteiros grandes não negativos
 * @param  A primeiro vetor de inteiros
 * @param  B segundo vetor de inteiros
 * @return   vetor de inteiros contendo a multiplicação entre o vetor A e B
 */
int *multiplicacao(int *A, int *B){
	int i;
	int *resultado = NULL;
	int maximo = MAX(A[0], B[0]);

	resultado = (int *) calloc(((maximo * 2) + 1), sizeof(int));
	resultado[0] = maximo * 2;

	for(i = 1; i < B[0] + 1; i++){
		resultado = soma(resultado, multiplicaIndividual(A, B[i], i - 1));
	}

	// Atualizando tamanho do vetor resultado, necessário quando o vetor resultado fica com um monte de 0 a esquerda
	i = abs(resultado[0]);
	while (resultado[i] == 0) {
		// Caso o resultado for positivo
		if(resultado[0] < 0)
			resultado[0] += 1;
		// Caso for negativo
		else if(resultado[0] > 0)
			resultado[0] -= 1;
		i--;
	}

	return resultado;
}

void somaUm(int *A){
	int i = 1;
	int valor;
	int excesso;

	valor = A[i] + 1;
	A[i] = valor % 10;
	excesso = valor / 10;

	while(excesso != 0){
		i++;
		valor = A[i] + 1;
		A[i] = valor % 10;
		excesso = valor / 10;
		if(i > A[0]){
			A[0] += 1;
		}
	}
}

// Auxiliar para a divisão
void subtracaoAlternativa(int *A, int *B, int *resultado){
	int i;
	int maior;
	int subtracao;
	int empresta = 0;
	int maximo = MAX(A[0], B[0]);

	maior = ehMaior(A, B);
	// Caso A > B
	if(maior == 1){
		for(i = 1; i < maximo + 1; i++){
			if(A[i] + empresta >= B[i]){
				subtracao = A[i] - B[i] + empresta;
				empresta = 0;
			}
			else{
				subtracao = 10 + A[i] - B[i] + empresta;
				empresta = -1;
			}
			resultado[i] = subtracao;
		}
	}
	// Caso B > A
	else if(maior == -1){
		for(i = 1; i < maximo + 1; i++){
			if(B[i] + empresta >= A[i]){
				subtracao = B[i] - A[i] + empresta;
				empresta = 0;
			}
			else{
				subtracao = 10 + B[i] - A[i] + empresta;
				empresta = -1;
			}
			resultado[i] = subtracao;
		}
		resultado[0] *= -1;
	}
	// Caso os dois números forem identicos, não precisa fazer conta
	else{
		resultado[0] = 1;
		resultado[1] = 0;
		return;
	}

	// Atualizando tamanho do vetor resultado, necessário quando o vetor resultado fica com um monte de 0 a esquerda
	i = abs(resultado[0]);
	while (resultado[i] == 0) {
		// Caso o resultado for positivo
		if(resultado[0] < 0)
			resultado[0] += 1;
		// Caso for negativo
		else if(resultado[0] > 0)
			resultado[0] -= 1;
		i--;
	}
}

// Não está completa
int *divisao(int *A, int *B){
	int *resultado = NULL;
	int maior = ehMaior(A, B);
	int maximo = MAX(A[0], B[0]);

	// Casos mais simples, quando B > A, ou seja, a divisão inteira é zero
	// e quando A == B, ou seja, a divisão é um
	if(maior <= 0){
		resultado = (int *) malloc (2 * sizeof(int));
		resultado[0] = 1;
		// De forma simplificada se == recebe 1, caso < recebe 0
		resultado[1] = maior + 1;
		return resultado;
	}

	resultado = (int *) malloc (maximo * sizeof(int));
	resultado[0] = 1;
	resultado[1] = 0;

	while(ehMaior (A, B) >= 0){
		subtracaoAlternativa(A, B, A);
		somaUm(resultado);
	}

	return resultado;
}