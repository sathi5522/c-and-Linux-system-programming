// C Program to add two numbers 
// without using arithmetic operator 
#include<stdio.h> 
  
int Add(int x, int y) 
{ 
    // Iterate till there is no carry   
    while (y != 0) 
    { 
        // carry now contains common  
        //set bits of x and y 
        int carry = x & y;  //1. 0000 1111 & 0010 0000 = 0000 0000 
  
        // Sum of bits of x and y where at  
        //least one of the bits is not set 
        x = x ^ y;  // 1. x = 0000 1111 ^ 0010 0000 = 0010 1111
  
        // Carry is shifted by one so that adding 
        // it to x gives the required sum 
        y = carry << 1; 
    } 
    return x; 
} 
  
int main() 
{ 
    printf("%d \n", Add(15, 32)); 
    return 0; 
} 
