#include <stdio.h>
#include <string.h>

	struct msg
	{
		int k;
		char n[20];
	};


int main()
{
	unsigned int i,j;
	struct msg a[5],tmp;

	strcpy(a[0].n, "nagesh");
	strcpy(a[1].n, "gunna s");
	strcpy(a[2].n, "hello");
	strcpy(a[3].n, "raja");
	strcpy(a[4].n, "gabbar singh");

	a[0].k = strlen(a[0].n);
	a[1].k = strlen(a[1].n);
	a[2].k = strlen(a[2].n);
	a[3].k = strlen(a[3].n);
	a[4].k = strlen(a[4].n);
	

	for(i = 0; i < 5; i++){
	for(j = i+1 ; j < 5; j++){

		if(a[i].k > a[j].k)
			a[i].k = a[i].k;
		else{
			tmp.k = a[i].k;
			a[i].k = a[j].k;
			a[j].k = tmp.k;
			
			strcpy(tmp.n, a[i].n);
			strcpy(a[i].n,a[j].n);
			strcpy(a[j].n, tmp.n);
			
			}
			
	}
	}	
	
	for(i = 0; i < 5; i++)
	printf("%d\n%s\n",a[i].k,a[i].n); 
	
	return 0;



}
