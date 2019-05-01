#include<stdio.h> 
#include<string.h> 


char * itob(int n, char s[], int b) { 

    //char s[100]; 
    int i = 0;
    while(n!=0) {    

        int temp  = 0; 

        temp = n % b; 
            
        if(temp < 10) { 
            s[i] = temp + '0'; 
            i++; 
        } 
        else { 
            s[i] = temp + 'A' - 10; 
            i++; 
        } 
            
        n = n/b; 
    }  
        
    //for(int j=strlen(s)-1; j>=0; j--) {
    //    printf("%s", s[j]); 
    //} da seg fold
    return s; 
} 

int main() { 
    int n = 120;	 
    int b = 16;
    char s[100];
    printf("%s\n", itob(n, s, b)); 
    return 0; 
} 
