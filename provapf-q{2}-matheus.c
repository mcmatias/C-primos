#include <stdio.h>   
#include <string.h> 


int main(int argc, char *argv[])   {       
	
	int arga = 0;//false
	int argA = 0;//false
	int argumentoc = 0;//false
	int argp = 0;//false
	int argInvalido = 0;
	
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
	
	if (arga && argA && argumentoc && argp) {
		printf("argumento -a -A -c -p\n");
	} else {
		if (arga) {
			printf("argumento -a\n");
		}
		if (argA) {
			printf("argumento -A\n");
		}
		if (argumentoc) {
			printf("argumento -c\n");
		}
		if (argp) {
			printf("argumento -p\n");
		}
	}

	
	
	return 0;   
} 
