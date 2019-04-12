#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define N 10000
    
int testaPrimo (int numero, int numerosPrimos[]) {

    long i;
	int isPrimo = 1;

	for(i=0; (numerosPrimos[i]*numerosPrimos[i]) <= numero; i++){
		if((numero%numerosPrimos[i])==0) {
            isPrimo = 0;
        } 
	}

	return isPrimo;
}
    
  
int main (void) {

    int n = 0;
    int numero = 0;
    int numerosPrimos [N];
	long primos = 0;
    

    for (n=0; n<N; n++){
		numerosPrimos[n]=0;
	}
	numerosPrimos[0]=2;

    for (numero = 2; primos<N; numero++) {
        if(testaPrimo(numero, numerosPrimos)){
			numerosPrimos[primos] = numero;
			primos ++;
		}
    }

    for (n=0; n<N; n++){
		printf("%d:  %d \n", n+1, numerosPrimos[n]);
	}    
	
	return 0;
}



