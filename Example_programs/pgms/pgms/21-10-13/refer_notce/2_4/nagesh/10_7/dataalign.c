#include <stdio.h>

int main()
{
	struct A {

	int a ;
	int c;
	int l;
	};



	struct B {
	int d;
	char e;
	short int f;
	};


	struct C{

	int a;
	char l;
	char d;
	int f;

	};


	printf("size of A :%d\n", sizeof (struct A ));

	printf("size of B :%d\n",sizeof(struct B));
	
	printf("size of C :%d\n", sizeof(struct C));

	
}
