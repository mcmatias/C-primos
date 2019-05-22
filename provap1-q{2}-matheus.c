#include<stdio.h> 
#include<string.h> 
#include<ctype.h>


#define MAXCHAR 1000
#define N 26

char transpoeLetra(int posLetra, char nRepeticoes, int letraMinuscula) {
	
	printf("entrou transpoeLetra\n");
	char alfabetoMaiusculo[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '\0'};
	char alfabetoMinusculo[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', '\0'};
	char letra;
	printf("posLetra %d\n", posLetra);
	printf("nRepeticoes %d\n", nRepeticoes);
	if(letraMinuscula){
		letra = alfabetoMinusculo[posLetra+nRepeticoes];
	} else {
		letra = alfabetoMaiusculo[posLetra+nRepeticoes];
	}
	
	printf("letra transporta %c\n", letra);
	
	return letra;
	printf("fim transpoeLetra");
	printf("\n==========================\n");
}


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

	return nRepeticoes;
}

void montaChave(char str[], int repetidos[], char criptografado[]) {
	
	printf("\n\n ==========================\n");
	printf("\n\n entrou montaChave \n\n");
	int posicao = 0;
	int nRepeticoes = 0;
	int iteracoes = 0;
	int letraMinuscula = 0;
	//printf("repetido %s\n", repetidos);

	for (int i=0; i<strlen(str); i++) {
		if(str[i] !=EOF && str[i]!='\n') {
		printf("char atual %c\n", str[i]);
		posicao = posicaoLetra(str[i]);
		nRepeticoes = contaAparicoes(posicao, repetidos);
		printf("posicao %d\n", posicao);
		printf("nRepeticoes %d\n", nRepeticoes);
		
		if(islower(str[i])) {
			letraMinuscula = 1;//1 eh true
		} else {
			letraMinuscula = 0;
		}
		
		criptografado[i] = transpoeLetra(posicao, nRepeticoes, letraMinuscula);
		iteracoes = i;
		printf("+++++++++++++++\n criptografado[i] %c\n", criptografado[i]);
		}
	}
	criptografado[iteracoes+1] = '\0';
	printf("+++++++++++++++\n criptografado %s\n", criptografado);

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
    
    int repetidos[N] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	char criptografado[100];
	criptografado[0] = '\0';
	
 
    montaChave(str, repetidos, criptografado);
    printf("+++++++++++++++\n criptografado %s", criptografado);
    
    return 0;
} 
