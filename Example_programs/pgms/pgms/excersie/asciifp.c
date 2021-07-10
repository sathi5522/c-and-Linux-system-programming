#include<stdio.h>

void f0(char c)
{
	printf("%c %d \n",c,c);
	
}
void f1(char c)
{
	printf("%c %d \n",c,c);
	
}
void f2(char c)
{
	printf("%c %d \n",c,c);
	
}
void f3(char c)
{
	printf("%c %d \n",c,c);
	
}
void f4(char c)
{
	printf("%c %d \n",c,c);
	
}
void f5(char c)
{
	printf("%c %d \n",c,c);
	
}
void f6(char c)
{
	printf("%c %d \n",c,c);
	
}
void f7(char c)
{
	printf("%c %d \n",c,c);
	
}
void f8(char c)
{
	printf("%c %d \n",c,c);
	
}
void f9(char c)
{
	printf("%c %d \n",c,c);
	
}
void f10(char c)
{
	printf("%c %d \n",c,c);
	
}
void f11(char c)
{
	printf("%c %d \n",c,c);
	
}
void f12(char c)
{
	printf("%c %d \n",c,c);
	
}
void f13(char c)
{
	printf("%c %d \n",c,c);
	
}
void f14(char c)
{
	printf("%c %d \n",c,c);
	
}
void f15(char c)
{
	printf("%c %d \n",c,c);
	
}
void f16(char c)
{
	printf("%c %d \n",c,c);
	
}
void f17(char c)
{
	printf("%c %d \n",c,c);
	
}
void f18(char c)
{
	printf("%c %d \n",c,c);
	
}
void f19(char c)
{
	printf("%c %d \n",c,c);
	
}
void f20(char c)
{
	printf("%c %d \n",c,c);
	
}
void f21(char c)
{
	printf("%c %d \n",c,c);
	
}
void f22(char c)
{
	printf("%c %d \n",c,c);
	
}
void f23(char c)
{
	printf("%c %d \n",c,c);
	
}
void f24(char c)
{
	printf("%c %d \n",c,c);
	
}
void f25(char c)
{
	printf("%c %d \n",c,c);
	
}

int main() 
{
	char ch;
	printf("enter the character");
	scanf("%c",&ch);
	int n;
	n = ch - 65; 
	
	void (*fp[26]) (char) = {f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25};
	(*fp[n])(ch);

	return 0;
}

