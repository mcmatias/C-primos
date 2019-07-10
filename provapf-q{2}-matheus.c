#include <stdio.h>   
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#define STRSIZE 100
#define MAXLINE 100
#define N 26

int posicaoLetra (char letra) {
	
	//printf("\n\n entrou posicaoLetra \n\n");
	char alfabeto[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '\0'};
	int posicao = 0;
	for (int i=0; i<strlen(alfabeto); i++) {
		if(alfabeto[i] == toupper(letra)) {
			posicao = i;
			//printf("posicao char atual %d\n", posicao);
		}
	}
	
	return posicao;
}

int contaAparicoes(int posLetra, int repetidos[]) {


	int nRepeticoes = repetidos[posLetra];
	repetidos[posLetra]++;
	nRepeticoes++;  

	return nRepeticoes;
}

char modificaText(char letra, int arga, int argA, int argumentoc, int argp, int repetidos[]) {
	
	int posicao = 0;
	int nRepeticoes = 0;
	
	if (arga && argA && argumentoc && argp) {
		printf("argumento -a -A -c -p\n");
	} else {
		if (arga && argA) {
			if (isupper(letra)) {
				letra = tolower(letra);
				//printf("letra minuscula %c\n", letra);
			} else if (islower(letra)) {
				letra = toupper(letra);
				//printf("letra maiuscula %c\n", letra);
			}
		} else {
			if (arga) {
				//printf("argumento -a\n");
				if (isupper(letra)) {
					letra = tolower(letra);
				}
				//printf("letra minuscula %c\n", letra);
			}
			if (argA) {
				//printf("argumento -A\n");
				if (islower(letra)) {
					letra = toupper(letra);
				}
				//printf("letra minuscula %c\n", letra);	
			}	
		}
 
		if (argumentoc) {
			if(!isspace(letra)) {
				//printf("argumento -c\n");
				posicao = posicaoLetra(letra);
				nRepeticoes = contaAparicoes(posicao, repetidos);
				printf("letra %c repetida %d vezes\n", letra, nRepeticoes);
			}

		}
		if (argp) {
			//printf("argumento -p\n");
		}
	}
	
	return letra;
}


void lerArquivo(char *texto[], int arga, int argA, int argumentoc, int argp, int repetidos[]) {
	char str[ STRSIZE ];
	char *linha;
	int i = 0;
	
	while (fgets( str, STRSIZE, stdin ) != NULL) {

		int tamanhoLinha;
		tamanhoLinha = strlen(str);
		//printf("tamanho linha: %d \n", tamanhoLinha-1);

		linha = (char *)calloc(tamanhoLinha,sizeof(char)*tamanhoLinha);
		linha = NULL;
		linha = str;
		
		//printf( "linha %s", linha);
		for (int n=0; n<tamanhoLinha-1; n++) {
			linha[n] = modificaText(linha[n], arga, argA, argumentoc, argp, repetidos);
		}
//
		texto[i] = linha;
		printf( "%s\n", texto[i]);
		i++;
		//strcpy(empresaNoh->nome, str);
		
	}

}

int main(int argc, char *argv[])   {       
	
	int arga = 0;//false
	int argA = 0;//false
	int argumentoc = 0;//false
	int argp = 0;//false
	int argInvalido = 0;
	int nLinhas = 0;
	//char texto[100];
	char *texto[MAXLINE];
	int repetidos[N] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	for (int i=1; i< argc; i++) {
		int c;
		c=*++argv[i];
		if (c == 'a') {
			arga = 1;//true
			//printf("argumento -a\n");
		} else if (c == 'A') {
			argA = 1;//true
			//printf("argumento -A\n");
		} else if (c == 'c') {
			argumentoc = 1;//true
			//printf("argumento -c\n");
		} else if (c == 'p') {
			argp = 1;//true
			//printf("argumento -p\n");
		} else {
			argInvalido = 1;
			//printf("argumento invalido: %c\n", c);
		}
	}	
	
	if (argInvalido) {
		printf("argumento invalido\n");
		return 1;
	}
	


	lerArquivo(texto, arga, argA, argumentoc, argp, repetidos);
	
	
	return 0;   
} 
