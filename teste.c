#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
 
#define STRSIZE 10
 
 struct node
	{
		char valor[5];
		struct node *pLink;
	};
	
	struct empresa
	{
		char nome[10];
		struct node *pLink;
	};
	
	//int buscaNoh(struct empresa *empresaAtual); 
 
int buscaNoh(struct empresa *empresaAtual) {
	printf("entrou buscaNoh");
	struct node *valorNoh = NULL;
	valorNoh = (struct node*) malloc(sizeof(struct node*));
	valorNoh = empresaAtual->pLink;
	int i = 0;
	while (valorNoh->pLink != NULL) {
		i++;
		printf("passou %d vezes", i);
	}
	
	return i;
}
 
int main(void)
{

	
	
	
	//struct empresa {
		//char *word;
		//struct node *pLink;
	//} empresas[NKEYS];
	
	char ticker[10][10];
	int nTickers = 0;
	int primeiroDigit = 1;
	struct empresa *empresaNoh = NULL;
	struct node *valorNoh = NULL;
	
	struct node *teste = NULL;

	char str[ STRSIZE ];
	while (fgets( str, STRSIZE, stdin ) != NULL) {
		printf( "%s", str );
		
		
		struct empresa *empresaAnterior = NULL;
		
		
		struct node *anterior = NULL;
		
		anterior = (struct node*) malloc(sizeof(struct node*));
		empresaAnterior = (struct empresa*) malloc(sizeof(struct empresa*));
		
		if(isalpha(str[0])){
			empresaNoh = (struct empresa*) malloc(sizeof(struct empresa*));
			printf("leu alpha\n");
			nTickers ++;
			printf("*str %c\n", *str);
			strcpy(ticker[nTickers], str);
			printf("ticker0 %s", ticker[nTickers]);
			strcpy(empresaNoh->nome, str);
			primeiroDigit = 1;
			printf("empresaNoh->nome %s", empresaNoh->nome);
			empresaAnterior = empresaNoh;
		} else if(isdigit(str[0])){
			//tentativa de criar struct dos valores
			printf("leu digit\n");
			valorNoh = (struct node*) malloc(sizeof(struct node*));
			printf("*str %c\n", *str);
			strcpy(valorNoh->valor, str);
			printf("valorNoh->valor %s", valorNoh->valor);
			
			if(primeiroDigit) {
				printf("entrou\n");
				primeiroDigit = 0;
				empresaAnterior->pLink = valorNoh;
				teste = (struct node*) malloc(sizeof(struct node*));
				teste = empresaAnterior->pLink;
				printf("teste->valor %s", teste->valor);
				printf("terminou\n");
			} else {
				anterior->pLink = valorNoh;
			}
			valorNoh->pLink = NULL;
			anterior = valorNoh;
			
		}
		
	}
	
	printf("empresaNoh->nome %s", empresaNoh->nome);
	struct node *no = NULL;
	no = (struct node*) malloc(sizeof(struct node*));
	no = empresaNoh->pLink;
	printf("valorNoh->valor %s", no->valor);
	buscaNoh(empresaNoh);
	

	
	
	return 0;
}
