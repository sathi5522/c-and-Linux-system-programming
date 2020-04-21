#include <stdio.h> 

int linearSearch(int arr[], int r, int x) 
{ 
	int i = 0;
	for(i=0; i < r; i++) {

		if(arr[i] == x) 
			return i;
	}  

	// if we reach here, then element was 
	// not present 
	return -1; 
} 

int main(void) 
{ 
	int arr[] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int x = 44; 
	int result = linearSearch(arr, n, x); 
	(result == -1) ? printf("Element is not present"
			" in array\n") 
		: printf("Element is present at "
				"index %d\n", 
				result); 
	return 0; 
} 
