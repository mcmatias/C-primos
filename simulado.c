#include<stdio.h> 
#include<string.h> 
#include<ctype.h>

char * toUpper(char frase[]) {
	
	for(int i = 0; i<strlen(frase); i++){
		frase[i] = toupper(frase[i]);
	}
	printf("%s\n", frase);
	
	return frase;
} 

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

char * limpaFrase(char frase[]) {
	
	char valoresPossiveis[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z', ',', '.', ' '};
	int tamanho = strlen(frase);
	char fraseTemp[tamanho];

	
	
	for(int i = 0; i<strlen(frase); i++){
		for(int n = 0; n<strlen(valoresPossiveis); n++){
			if(frase[i] == valoresPossiveis[n]) {
			    printf("%c\n", frase[i]);
                append(fraseTemp, frase[i]);
                break;
			} 
		}

	}
	//problema: to retornando fraseTemp que é variavel local
	//como zerar o char frase[] p poder colocar só os valores do fraseTemp dentro dele?
	printf("%s\n", fraseTemp);
	return fraseTemp;
} 


 
int main() { 
	char frase[] = "matheus123";
    toUpper(frase);
    limpaFrase(frase);
    //geraChave();
    return 0; 
} 