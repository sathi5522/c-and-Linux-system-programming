#include <stdio.h> 
#define CHAR_BIT 8 

/* This function will return absolute value of n*/
unsigned int getAbs(int n) 
{ 
	int const mask = n >> (sizeof(int) * CHAR_BIT - 1); // 6 - 0000 0110
							    // ~ - 1111 1001
							    //             1
							    //-6 - 1111 1010 >> 31 = 1111 1111
	return ((n + mask) ^ mask); 		  	    // n - 1111 1010
							 //+ mask- 1111 1111
							    //=  - 1111 1001
							  //^mask- 1111 1111
							    //=  - 0000 0110 
} 

/* Driver program to test above function */
int main() 
{ 
	int n = -6; 
	printf("Absoute value of %d is %u", n, getAbs(n)); 

	getchar(); 
	return 0; 
} 
