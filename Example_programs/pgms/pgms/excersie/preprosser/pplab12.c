#include<stdio.h>

#define IS_REG(a,pos) (a >> (pos - 1)) & 1
#define IS_CHAR(a,pos) (a >> (pos - 1)) & 1
#define IS_BLOCK(a,pos) (a >> (pos - 1)) & 1
#define IS_LINK(a,pos) (a >> (pos - 1)) & 1
#define IS_DIR(a,pos) (a >> (pos - 1)) & 1
#define IS_FIFO(a,pos) (a >> (pos - 1)) & 1
#define IS_SOCKET(a,pos) (a >> (pos - 1)) & 1

int main()
{
	int x = 10;
	printf("%d\n",IS_REG(x,1));
	printf("%d\n",IS_CHAR(x,2));
	printf("%d\n",IS_BLOCK(x,3));
	printf("%d\n",IS_LINK(x,4));
	printf("%d\n",IS_DIR(x,5));
	printf("%d\n",IS_FIFO(x,6));
	printf("%d\n",IS_SOCKET(x,7));

	return 0;
}
