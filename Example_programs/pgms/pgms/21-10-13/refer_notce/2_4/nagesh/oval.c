#include <stdio.h>

int main()
{

	char c;

	printf("enter any character\n");
	scanf("%c",&c);

	switch(c){
		
		case 'a': printf("it is a oval");
			break;

		case 'e': printf("it is a oval");
			break;

		case 'i': printf("it is a oval");
			break;

		case 'o': printf("it is a oval");
			break;
		
		case 'u': printf("it is a oval");
			break;

		default : printf("it is not a oval");
	}

	return 0;
}
