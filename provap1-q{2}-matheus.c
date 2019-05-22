#include<stdio.h> 
#include<string.h> 
#include<ctype.h>


#define MAXCHAR 1000
#define N 26

int posicaoLetra (char letra) {
	
	printf("\n\n entrou posicaoLetra \n\n");
	char alfabeto[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '\0'};
	int posicao = 0;
	for (int i=0; i<strlen(alfabeto); i++) {
		if(alfabeto[i] == toupper(letra)) {
			posicao = i;
			printf("posicao char atual %d\n", posicao);
		}
	}
	
	return posicao;
}

void contaAparicoes(char str[], char repetidos[]) {
	
	
	printf("\n\n entrou contaAparicoes \n\n");
	int posicao = 0;
	
	for (int a=0; a<strlen(repetidos); a++) {
		printf("%d - repetidos[posicao] %c\n", a, repetidos[a]);
	}
	
	 for (int i=0; i<strlen(str); i++) 
    { 
		if(str[i] !=EOF && str[i]!='\n') {
			printf("char atual %c", str[i]);
			posicao = posicaoLetra(str[i]);
			printf("RETORNO posicao char atual %d\n", posicao);
			repetidos[posicao]++;  
			printf("repetidos[posicao] %c", repetidos[posicao]); 
			printf("\n-------------------------------------\n");  
		}
  
    } 
    
    printf("\n\n repetidos %s\n\n", repetidos);

}



int main() { 
	FILE *fp;
    char str[MAXCHAR];
    char* filename = "arquivoP1{q2}.txt";
    
 
    int n=0;
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL) {
		n++;
	}
        printf("%s", str);
        n = strlen(str);
		printf("n %d\n", n);
		str[n+1] = '\0';
        
    fclose(fp);
    
    char repetidos[N+1] = "00000000000000000000000000\0";
	
    contaAparicoes(str, repetidos);
    return 0;
} 
