#include<stdio.h>

int xyz(int x,int y)
{
	printf("in xyz\n");
	return 0;
}
int *mnp(int x,int y)
{
	printf("in mnp\n");
	return NULL;
}
int def(int x,int y)
{
	printf("in def\n");
	return 0;
}

int (*abc(int (*fp1)(int ,int),int *(*fp2)(int ,int)))(int ,int)
{
	(*fp1)(10,20);
	(*fp2)(10,20);
	return def;
}

int main()
{
/*	int (*fp)(int,int);
	fp = abc(xyz,mnp);
	(*fp)(10,20);*/
	(*abc(xyz,mnp))(10,20);
	return  0;
}
