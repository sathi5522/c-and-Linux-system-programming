#include <stdio.h>


unsigned int  sqr(int no)
{

	
	
	static int y = 3;
			 
		if(no > 0){
			return no * no;
		}

	     
	    y++;

		return y * y;


}


int main()
{


	int a = 3,r;
	
	r = sqr(a);
	printf("%d\n", r);

	r = sqr(0);
	printf("%d\n",r);

	r = sqr(0);
	printf("%d\n",r);
	
	return 0;

}
