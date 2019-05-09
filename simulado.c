#include<stdio.h> 
#include<string.h> 
#include<ctype.h>

void toUpper(char frase[]) {
	
	for(int i = 0; i<strlen(frase); i++){
		frase[i] = toupper(frase[i]);
	}
	printf("toUpper %s\n", frase);
	
	
} 

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

void limpaFrase(char frase[]) {
	//preciso acertar
	//tenho que limpar valores iguais tb
	char valoresPossiveis[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', ',', '.', ' ', '\0'};
	char repetidos[100]; 
	int tamanho = strlen(frase);
	char fraseTemp[tamanho];
	
	
	fraseTemp[0] = '\0';
	repetidos[0] = '\0';
	
	for(int i = 0; i<strlen(frase); i++){
		for(int n = 0; n<strlen(valoresPossiveis); n++){
		    int ehRepetido = 0;//false
			if(frase[i] == valoresPossiveis[n]) {
			    for(int m=0; m<strlen(repetidos); m++){
			        if(frase[i] == repetidos[m]){
			            ehRepetido = 1;//true
			            //printf("Repetido %c\n", frase[i]);
			            break;
			        }
			    }
			    if(!ehRepetido) {
		            printf("%c\n", frase[i]);
                    append(fraseTemp, frase[i]);//possiveis
                    append(repetidos, frase[i]);//como é valor possivel, add ao repetidos pq nao pode ser usado novamente
                    //printf("Array de repetidos %s\n", repetidos);
                    break; 
			    }
			} 
		}

	}
	
	int ultimoCaracter = 0;
	for(int i=0; i<strlen(fraseTemp); i++) {
		frase[i] = fraseTemp[i];
		ultimoCaracter = i;
		}
	frase[ultimoCaracter+1] = '\0';
	
	printf("%s\n", fraseTemp);
	printf("limpaFrase %s\n", frase);
} 

void completaChave(char frase[]) {
	
	char valoresPossiveis[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', ',', '.', ' ', '\0'};
	
	int addValor;
	for(int n = 0; n<strlen(valoresPossiveis); n++){
		addValor = 1; //add valor true
		for(int i = 0; i<strlen(frase); i++){
			if(frase[i] == valoresPossiveis[n]) {
				addValor = 0;//add valor = false
                break;
			} 
		}
		if(addValor) {
			append(frase, valoresPossiveis[n]);
		}
	}

	frase[strlen(frase)+1] = '\0';
	
	printf("completaChave %s\n", frase);
	
} 

void geraChave(char frase[]) {
	
	int indice  = 0;
	
	
	for(int i=0; i<strlen(frase); i++) {
		
		char valoresPossiveis[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', ',', '.', ' ', '\0'};
		int valorFrasei;
		for(int n=0; n<strlen(valoresPossiveis); n++) {
				if(valoresPossiveis[n] == frase[i]) {
					valorFrasei = n+1;
					break;
				}
		}
		
		
		//if(valorFrasei < strlen(frase)) {
		//    indice = valorFrasei;
		//} else {
		//    valorFrasei = valorFrasei - 29;
		//    indice = valorFrasei;
		//}
		
		indice = (valorFrasei % strlen(valoresPossiveis))+indice; //p poder ser circular
	    // to gerando certo ate o APQS - o  x nem fazendo a mao to chegando
	    // estando no S da chave o indice seguinte é 35
		printf("indice %d\n", indice);
		frase[i] = frase[indice];	
		
	}
	
	printf("geraChave %s\n", frase);
	
}
 
int main() { 
	char frase[100] = "celacanto provoca maremoto";
    toUpper(frase);
    limpaFrase(frase);
    completaChave(frase);
    geraChave(frase);
    return 0; 
} 