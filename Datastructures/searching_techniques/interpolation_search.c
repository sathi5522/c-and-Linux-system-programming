// C program to implement iterative Binary Search 
#include <stdio.h> 

// A iterative binary search function. It returns 
// location of x in given array arr[l..r] if present, 
// otherwise -1 
int interpolationSearch(int arr[], int l, int r, int x) 
{ 
	int comparisons = 1;
	int m;
	while (l <= r) {
		printf("\nComparison %d  \n" , comparisons ) ;
		printf("lo : %d, list[%d] = %d\n", l, l, arr[l]);
		printf("hi : %d, list[%d] = %d\n", r, r, arr[r]); 
		comparisons++;
		m = l + (((double)(r - l) / (arr[r] - arr[l])) * (x - arr[l])); 
		printf("mid %d arrm[m] = %d\n",m, arr[m]); 
		// Check if x is present at mid 
		if (arr[m] == x) { 
			return m; 
		} else {
			// If x greater, ignore left half 
			if (arr[m] < x) 
				l = m + 1; 

			// If x is smaller, ignore right half 
			else
				r = m - 1; 
		} 


	}
	// if we reach here, then element was 
	// not present 
	return -1; 
} 


int main(void) 
{ 
	int arr[] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int x = 31; 
	int result = interpolationSearch(arr, 0, n - 1, x); 
	(result == -1) ? printf("Element is not present"
			" in array\n") 
		: printf("Element is present at "
				"index %d\n", 
				result); 
	return 0; 
} 
