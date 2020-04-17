#include <stdio.h> 
  
// function to toggle bits in the given range 
unsigned int setBitsFromLToR(unsigned int n, 
                                unsigned int l, unsigned int r) 
{ 
    // calculating a number 'num' having 'r' 
    // number of bits and bits in the range l 
    // to r are the only set bits 
    int num = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);  //0001 1111 ^ 0000 0000 = 0001 1111 
  
    // toggle bits in the range l to r in 'n' 
    // and return the number 
//Besides this, we can calculate num as: num=(1<<r)-l . 
    return (n & ~num); //  0011 1111 & 1110 0000 = 0010 0000
} 
  
// Driver program to test above 
int main() 
{ 
    unsigned int n = 63;   //0011 1111 
    unsigned int l = 1, r = 5; 
    printf("%u \n",setBitsFromLToR(n, l, r)); 
    return 0; 
} 
