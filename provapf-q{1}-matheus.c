#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

int conversorFahrCelsius (int fahr) {
	
    int celsius;

    
    celsius = 5* (fahr - 32)/9;

    
    return celsius;
}

int conversorCelsiusFahr (int celsius) {
    int fahr;
    

    fahr = (1.8 * celsius) + 32;

    return fahr;
}

int main (void) {
	int temperatura = 0;
	int temperaturaConvertida = 0;
	char escala;
	int c;
	
	scanf ("%d", &temperatura);
	while((c = getchar()) != '\n') {
		if (isalpha(c)) {
			//printf("%c \n", c);
			escala= c;
			escala = toupper(escala);
		}
	  }
	  
	if (escala == 'C') {
		printf("temperatura em Celsius: %d\n", temperatura);
		temperaturaConvertida = conversorCelsiusFahr(temperatura);
		printf ("Temperatura em Fahrenheit: %d\n", temperaturaConvertida);
	} else if(escala == 'F') {
		printf("temperatura em Fahrenheit: %d\n", temperatura);
		temperaturaConvertida = conversorFahrCelsius(temperatura);
		printf ("Temperatura em Celsius: %d\n", temperaturaConvertida);
	} else {
		printf("escala inexistente\n");
	}
	  
	//printf ("antes do loop %c\n", escala);  
	//printf ("numero a ser convertido %d\n", temperatura);
	
	
	
   return 0;
}
