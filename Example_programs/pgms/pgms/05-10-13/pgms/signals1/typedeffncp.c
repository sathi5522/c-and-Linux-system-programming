#include<stdio.h>
typedef int (*fp_xyz)(int,int);
typedef int *(*fp_mnp)(int,int);
typedef int (*fp_def)(int,int);
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

fp_def(*abc(fp_xyz fp1,fp_mnp fp2))
{
	(*fp1)(10,20);
	(*fp2)(10,20);
	return def;	
}

int main()
{
	//(*abc(xyz,mnp))(10,20);
	fp_def fp;
	fp = abc(xyz,mnp);
	(*fp)(10,20);
	return  0;
}
