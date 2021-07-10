# include <stdio.h>

char swap(char a)
{
	a = (a << 4) | (a >> 4);
	return a;
	
}

int main(void)
{
	char b = 'A', c;

	c = swap(b);
	printf("%d\n",c);

	return 0;

}

