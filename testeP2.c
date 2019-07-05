#include<stdio.h> 
#include<string.h> 
#include<ctype.h>

int main (void) {
	int a = 0;
	char b[42];
	int i = 0;
	int c;
	
	scanf ("%d", &a);
	//printf("numero de vezes%d", a);
	while((c = getchar()) != '\n') {
		if (isalpha(c)) {
			//printf("%c \n", c);
			b[i] = c;
			i++;
		} else if (isspace(c)) {
			//printf("%c \n", c);
			b[i] = c;
			i++;
		}
	  }
	  
	//printf ("antes do loop %s", b);  
	for (int i = 0; i<a; i++) {
	  printf ("%d- %s\n", i+1, b); 
	}
	
   return 0;
}
