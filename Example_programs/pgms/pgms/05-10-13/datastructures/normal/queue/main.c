#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 6

struct msg{
	int data[MAX];
	int curr;
};

struct msg obj;
int enqueue(int arg)
{

	if(obj.curr > (MAX-1))
		return -1;

	obj.data[obj.curr] = arg;
		obj.curr++;
	printf("curr: %d\n", obj.curr);

	return 0;
}

int print(void)
{
	int i;
	if(!obj.curr)
		return -1;
	printf("curr: %d\n", obj.curr);

	for(i = 0; i<obj.curr; i++)
		printf("%d ",obj.data[i]);
	return 0;
}
int dequeue(void)
{
	int i,ret;
	ret = obj.data[0];

	for(i=0;i<obj.curr; i++){
		obj.data[i] = obj.data[i+1];
	}
	obj.curr --;
	return ret;
}
int main()
{
	int ret;
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	ret = enqueue(50);
	if(ret<0){
		printf("filled in 5th\n");
		return 0;
		}
	ret = enqueue(60);
	if(ret<0){
		printf("filled in 6th\n");	
	}
	ret = enqueue(70);
	if(ret<0){
		printf("filled in 6th\n");	
	}

	print();
	ret = dequeue();
	print();
	ret = dequeue();
	print();
	ret = dequeue();
	print();
	return 0;
}

