#include<stdio.h>

unsigned int write(unsigned int a,char ch)
{
	static int count = 0;
	if(count >= 4) {
		printf("character is full\n");
		return 0;
	}
	if(!count)
		a = ch;
	else {
		a = (a << 8) | ch;
	}
	
	count++;


	return a;	
}

unsigned int  read(unsigned int b,int pos)
{
	switch(pos) {
		case 1:
		return (b >> 24);
		case 2:
		return (b >> 16) & 0xff;
		case 3:
		return (b >> 8) & 0xff;
		case 4:
		return (b & 0xff);
		default:
		printf("please check pos");
		return -1;
	}

}

int main()
{
	unsigned int data;
	char r;
	data = write(data,'A');
	data = write(data,'B');
	data = write(data,'C');
	data = write(data,'D');
	//data = write(data,'E');
	
	//printf("%d\n",data);
	r = read(data,4);
	printf("%c\n",r);
}
