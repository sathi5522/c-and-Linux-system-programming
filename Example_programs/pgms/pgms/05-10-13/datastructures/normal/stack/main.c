#include<stdio.h>
#include<unistd.h>
#define MAX 100
struct manager{
	int data[MAX];
	int curr;
};

struct manager obj;

int push(int arg)
{
	int i;

	if(obj.curr > (MAX-1))
		return -1;
	for(i=obj.curr; i > 0; i--)
		obj.data[i] = obj.data[i-1];
	
	obj.data[0] = arg;
	obj.curr ++;
	return 0;
}
int print(void)
{
	int i;
	
	for(i=0;i < obj.curr; i++)
		printf("%d ", obj.data[i]);
	printf("\n");
}
int pop(void)
{

	int i,ret;
	ret = obj.data[0];

	for(i=0;i<obj.curr;i++)
		obj.data[i] = obj.data[i+1];
	obj.curr --;
	return 0;
}
int peek()
{
	int i;
	return obj.data[0];
}

int main()
{
	int ret;
	push(10);
	push(20);
	push(30);
	push(40);

	push(50);
	pop();
	ret = peek();
	printf("top of stack: %d\n", ret);

	print();
	pop();
	print();
	pop();
	print();
	pop();
	print();
	return 0;
}

