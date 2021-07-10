#include <stdio.h>

int main()
{
	int a;

	printf("enter value of a");
	scanf("%d",&a);

	switch(a){
		
		case 1: printf("sunday\n");
			break;

		case 2: printf("monday\n");
			break;

		case 3: printf("tuesday\n");
			break;

		case 4: printf("wednesday\n");
			break;

		case 5: printf("thursday\n");
			break;

		case 6: printf("friday\n");
			break;
		
		case 7: printf("saturaday\n");
			break;
		
		default : printf("no day");
		}
		
		return 0;
}
