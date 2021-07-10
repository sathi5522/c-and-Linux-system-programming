#include <stdio.h>
#include <string.h>

	struct fun{

		char a[20];
		
		};



unsigned int  ret(struct fun *p, char d)
{
	unsigned int i =0, k;

	while(p -> a[i++] != '\0'){

		if(p -> a[i] == d)
			return 1;
		//	i++;
		}

		return 0;


}







int main()
{


       	struct fun obj;
 	unsigned int r;
	strcpy(obj.a, "nagesh");
	
	r = ret(&obj,'k');

	printf("%d",r);

	return 0;
}
