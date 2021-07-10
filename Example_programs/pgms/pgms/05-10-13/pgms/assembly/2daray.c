#include<stdio.h>
void fun(int (*p)[2], int r, int c)
{
	int i, j;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++)
			printf("%d ", p[i][j]);
		printf("\n");

	}

}

int main()
{
	int a[2][2] = {{1,2}, {3, 4}};
	fun(a, 2, 2);
	
	return 0;
}
