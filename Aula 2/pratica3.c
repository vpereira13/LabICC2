/**
 * Laboratório de Introdução à Ciência da Computação II - SCC0220
 *
 * Prof: André Carlos Ponce de Leon Ferreira de Carvalho
 *
 * Aula 2
 * Exercício 1 - Busca em Arquivo
 * Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
// Por definição da especificação, usarei esses delimitadores
#define CARACTERES " \n\r\t."

/**
 * Função que tem dada duas palavras em um array, elas trocam de posição
 * @param palavra1 palavra a ser trocada indo para a posição da outra palavra
 * @param palavra2 palavra a ser trocada indo para a posição da primeira palavra
 */
void troca(char **palavra1, char **palavra2){
	char *aux = *palavra1;
	*palavra1 = *palavra2;
	*palavra2 = aux;
}

/**
 * Função auxiliar do quickSort, que dado um vetor de strings, pega o ultimo
 * elemento como pivo e coloca ele no lugar correto do vetor. Além disso, a
 * função deixa as strings “maiores” que o pivo a direita dele e as “menores”
 * a esquerda
 * @param  palavras vetor de strings
 * @param  inicio   índice do início do vetor
 * @param  fim      índice do último elemento do vetor
 * @return          índice da string que foi colocada no lugar certo
 */
int particao (char **palavras, int inicio, int fim){
	int i = (inicio - 1);
	int j;
	char *pivo = palavras[fim];

	for (j = inicio; j <= fim - 1; j++)
		if (strcmp(palavras[j], pivo) < 1){
			i++;
			troca(&palavras[i], &palavras[j]);
		}
	troca(&palavras[i + 1], &palavras[fim]);
	return (i + 1);
}

/**
 * Função de ordenação quicksort para strings
 * @param palavras vetor de palavras
 * @param inicio   índice do início do vetor
 * @param fim      índice do fim do vetor
 */
void quicksort(char **palavras, int inicio, int fim){
	int i;
	if (inicio < fim){
		i = particao(palavras, inicio, fim);
		quicksort(palavras, inicio, i - 1);
		quicksort(palavras, i + 1, fim);
	}
}

/**
 * Função para transformar uma string inteira em caixa baixa
 * @param string String a ser modificada
 */
void caixaBaixa(char *string){
	int i;

	for(i = 0; string[i] != '\0'; i++)
		if(string[i] >= 'A' && string[i] <= 'Z')
			string[i] += 32;
}

/**
 * Função para fazer uma busca mais eficiente de uma string em um vetor
 * previamente ordenado
 * @param  vetor   Vetor de strings previamente ordenado
 * @param  inicio  índice do início da busca
 * @param  fim     índice do final da busca
 * @param  chave   palavra chave a ser buscada
 * @return         valor do índice onde se encontra a palavra ou -1 se não achar
 */
int buscaBinaria(char **vetor, int inicio, int fim, char *chave){
	// Cálculo da metade do vetor
	int meio = (fim + inicio)/2;
	// Compara palavra chave com a posição meio do vetor
	int resultado = strcmp(chave, vetor[meio]);

	// Caso encontrou
	if(!resultado)
		return meio;
	// Caso não encontrou e acabou a busca
	// No caso é retornado o fim para ficar melhor para o programa, mesmo que
	// isso não seja o usual (retornar -1)
	if(fim <= inicio)
		return fim;
	// Procura novamente em cada metade
	else
		return resultado < 0 ? buscaBinaria(vetor, inicio, meio-1, chave) : buscaBinaria(vetor, meio+1, fim, chave);
}

/**
 * Função que le o conteúdo inteiro de um arquivo de texto e coloca em um
 * ponteiro de caracteres
 * @param  nomeArquivo string contendo o nome do arquivo
 * @return             ponteiro com o conteúdo do arquivo
 */
char *leConteudoArquivo(char *nomeArquivo){
	int tamanho;
	FILE *arquivo = NULL;
	char * conteudo = NULL;

	// Abrindo o arquivo
	arquivo = fopen(nomeArquivo, "r");

	// Descobrindo o tamanho em bytes do arquivo
	fseek (arquivo , 0 , SEEK_END);
	tamanho = (int) ftell(arquivo);
	rewind (arquivo);

	// Alocando e lendo o conteúdo
	conteudo = (char*) malloc (sizeof(char)*tamanho);
	fread (conteudo, 1, tamanho, arquivo);

	// Fechando o arquivo (liberando memória) e retornando o conteúdo
	fclose(arquivo);
	return conteudo;
}

/**
 * Função que procura a palavra chave em um vetor de palavras, conta a
 * quantidade de ocorrências e imprime o que o exercício pede
 * @param palavras vetor de palavras
 * @param tamanho  tamanho do vetor de palavras
 * @param chave    palavra a ser encontrada
 */
void encontra(char **palavras, int tamanho, char *chave){
	int i;
	int indice;
	int contador = 0;

	indice = buscaBinaria(palavras, 0, tamanho-1, chave);
	// Caso achar a palavra
	if(!strcmp(chave, palavras[indice])){
		// Voltando para ver se não tem repetidas antes
		while(indice > 0 && !(strcmp(chave, palavras[indice]))){
			indice--;
			if(!indice && !(strcmp(chave, palavras[indice])))
			contador = 1;
			else
			contador = 0;
		}
		indice++;
		while(indice < tamanho && !strcmp(chave, palavras[indice])){
			indice++;
			contador++;
		}

		printf("%s %d", chave, contador);
		for(i = indice; i < tamanho && i < indice + 3; i++)
		printf(" %s", palavras[i]);
		printf("\n");
	}
	// Caso não ache a palavra
	else{
		// Anda com o cursor para frente até a palavra do vetor ser maior que
		// a chave
		while(strcmp(chave, palavras[indice]) > 0)
			indice++;
		printf("%s %d", chave, contador);
		for(i = indice; i < tamanho && i < indice + 3; i++)
		printf(" %s", palavras[i]);
		printf("\n");
	}
}

int main (int argc, char *argv[]){
	int i;
	int n;
	int tamanho;
	char *nome = NULL;
	char *palavra = NULL;
	char *conteudo = NULL;
	char **palavras = NULL;
	char **buscadas = NULL;

	// Tratamento da entrada
	// Nome do arquivo e quantidade de palavras a serem buscadas
	nome = (char *) malloc (MAX * sizeof(char));
	scanf("%s %d", nome, &n);
	// Aloca memória para as palavras a serem buscadas
	buscadas = (char **) malloc (n * sizeof(char *));
	for(i = 0; i < n; i++)
		buscadas[i] = (char *) malloc (MAX * sizeof(char));
	// Recebe as palavras n buscadas
	for(i = 0; i < n; i++)
		scanf("%s", buscadas[i]);

	// Le o conteúdo do arquivo
	conteudo = leConteudoArquivo(nome);

	// Aloca um tamanho exagerado de memória para colocar as palavras
	palavras = (char **) malloc (strlen(conteudo) * sizeof(char *));

	// Separa as palavras e coloca em um vetor de palavras
	i = 0;
	palavra = strtok(conteudo, CARACTERES);
	do{
		caixaBaixa(palavra);
		palavras[i] = palavra;
		palavra = strtok(NULL, CARACTERES);
		i++;
	} while(palavra);

	tamanho = i;

	// Redimensiona o vetor, retira o tamanho desnecessário
	palavras = (char **) realloc (palavras, tamanho * sizeof(char *));

	// Ordena o vetor
	quicksort(palavras, 0, tamanho-1);

	// Encontra e imprime as palavras desejadas
	for (i = 0; i < n; i++)
		encontra(palavras, tamanho, buscadas[i]);

	// Liberando memória - AINDA PRECISA TERMINAR DE DESALOCAR MEMÓRIA
	free(nome);
	free(conteudo);
	free(palavra);
	for (i = 0; i < n; i++)
		free(buscadas[i]);
	free(buscadas);

	return 0;
}
