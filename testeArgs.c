#include <stdio.h>   
#include <string.h>   
#define MAXLINE 1000


int main(int argc, char *argv[])   {       
		
	for (int i=1; i< argc; i++) {
		int c;
		c=*++argv[i];
		if (c == 'a') {
			printf("argumento -a\n");
		} else if (c == 'b') {
			printf("argumento -b\n");
		} else {
			printf("argumento invalido: %c\n", c);
		}
	}	
	return 0;   
} 
