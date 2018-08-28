#include "operacoes.h"
#include <stdlib.h>
#include <stdio.h>

// Funções auxiliares para retornar o máximo ou o mínimo entre duas entradas
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

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

void soma(int *A, int *B, int *resultado){
	int i;
	int soma;
	int excesso = 0;
	int maximo = MAX(A[0], B[0]);

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
}

void subtracao(int *A, int *B, int* resultado){
	int i;
	int maior;
	int subtracao;
	int empresta = 0;
	int maximo = MAX(A[0], B[0]);

	// Alocando espaço para o resultado, como é subtração, vai precisar de no máximo a mesma quantidade de casas que o maior número entre A e B
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

/*
int *multiplicacao(int *A, int *B, int *resultado){

	return resultado;
}

int *divisao(int *A, int *B){

	return resultado;
}
*/
