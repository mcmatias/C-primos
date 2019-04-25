// C++ program to convert hexadecimal to decimal 
#include<iostream> 
#include<string.h> 
using namespace std; 

// Function to convert hexadecimal to decimal 
int hexadecimalToDecimal(char hexVal[]) 
{ 
	int len = strlen(hexVal); 
	
	// Initializing base value to 1, i.e 16^0 
	int base = 1; 
	
	int dec_val = 0; 
	
	// Extracting characters as digits from last character 
	for (int i=len-1; i>=0; i--) 
	{ 
     
      switch (hexVal[i])
			{
   				case 'a':
                  hexVal[i] = 'A';
   				break;

   				case 'b':
     			 hexVal[i] = 'B';
   				break;
          
             	case 'c':
     			 hexVal[i] = 'C';
   				break;
          
             	case 'd':
     			 hexVal[i] = 'D';
   				break;
          
             	case 'e':
     			 hexVal[i] = 'E';
   				break;
          
             	case 'f':
     			 hexVal[i] = 'F';
   				break;
	}
      
		// if character lies in '0'-'9', converting 
		// it to integral 0-9 by subtracting 48 from 
		// ASCII value. 
		if (hexVal[i]>='0' && hexVal[i]<='9') 
		{ 
			dec_val += (hexVal[i] - 48)*base; 
				
			// incrementing base by power 
			base = base * 16; 
		} 

		// if character lies in 'A'-'F' , converting 
		// it to integral 10 - 15 by subtracting 55 
		// from ASCII value 
		else if (hexVal[i]>='A' && hexVal[i]<='F') 
		{ 
			dec_val += (hexVal[i] - 55)*base; 
		
			// incrementing base by power 
			base = base*16; 
		} 
	} 
	
	return dec_val; 
} 

// Driver program to test above function 
int main() 
{ 
	char hexNum[] = "1A3F";	 
	printf("%d", hexadecimalToDecimal(hexNum)); 
	return 0; 
} 
