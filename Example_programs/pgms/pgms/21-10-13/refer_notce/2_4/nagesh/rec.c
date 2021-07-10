#include <stdio.h>

int main()
{
	int i, j;

	add(i,j);
	
	return 0;

}

int add(int x,int y)
{
	int g  ;
	x = 20;
	y = 20;
	g =  x+y;
	while (g < 60){
	g = x + y;
	 add(x,y);
       }
	printf("%d\n",g);

	return 0;


}

