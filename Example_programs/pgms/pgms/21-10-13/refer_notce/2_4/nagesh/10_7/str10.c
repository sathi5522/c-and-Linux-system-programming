#include <stdio.h>

	 struct msg{
		
	
	int s;

	
	};

void update(struct msg *q,int x )
{

	q->s = x;
}




int main()
{
	
	 struct msg obj = {20};
       	struct msg *p;
	int a = 7;


	p = &obj;

	update(&obj,7);

        printf("%d",p->s);

	return 0;

}
