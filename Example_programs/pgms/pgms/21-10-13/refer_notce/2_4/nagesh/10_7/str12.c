#include <stdio.h>

	struct c{
		
		int a;
		int b;

	};



unsigned int  swap(struct c *p)
{

	struct c tmp;
		
		
	tmp.a = p->a;
	tmp.b = p->b;

	

	p->a  = (p+1)->a;

	p->b  = (p+1)->b;
	
	 (p+1)->a = tmp.a;

	 (p+1)->b = tmp.b;
	
	return 0;

}






int main()
{

	struct c obj[2];

	obj[0].a = 10;
	obj[0].b = 20;

	obj[1].a = 30;
	obj[1].b = 40;

	swap(obj);

	printf("%d\n%d\n",obj[1].a,obj[1].b);
	
	return 0;


}
