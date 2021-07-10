#include <stdio.h>
#include <string.h>

struct emp{

	char name[20];
	int age;
	
	};

int main()
{
	struct emp e1 = {"gunnanagesh",22},e2 ={"kamesh", 23},temp;

	strcpy(temp.name,e1.name);
	strcpy(e1.name,e2.name);
	strcpy(e2.name,temp.name);
	e1.age = strlen(e1.name);
	printf("%d",e1.age);

	

	return 0;
}
