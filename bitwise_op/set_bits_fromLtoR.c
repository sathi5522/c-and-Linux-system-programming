#include <stdio.h> 
  
// function to toggle bits in the given range 
unsigned int setBitsFromLToR(unsigned int n, 
                                unsigned int l, unsigned int r) 
{ 
    // calculating a number 'num' having 'r' 
    // number of bits and bits in the range l 
    // to r are the only set bits 
    int num = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);  //0000 1111 ^ 0000 0001 = 0000 1110 
  
    // toggle bits in the range l to r in 'n' 
    // and return the number 
//Besides this, we can calculate num as: num=(1<<r)-l . 
    return (n | num); //  0011 0010 | 0000 1110 = 0011 1110
} 
  
// Driver program to test above 
int main() 
{ 
    unsigned int n = 50;   //0011 0010 
    unsigned int l = 1, r = 5; 
    printf("%u \n",setBitsFromLToR(n, l, r)); 
    return 0; 
} 
