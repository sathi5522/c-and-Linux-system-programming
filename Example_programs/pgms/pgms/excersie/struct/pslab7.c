#include<stdio.h>
struct s {
	int a;
	char s[10];
};
void fun(struct s *obj1, struct s *obj2)
{
	int temp;
	char t[10];
	strcpy(t, obj2->s);
	strcpy(obj2->s, obj1->s);
	strcpy(obj1->s, t);
	temp = obj1->a;
	obj1->a = obj2->a;
	obj2->a = temp;
	

	
// b = (a+b)- (a=b)		

}

int main()
{
	struct s obj1 = {10,"hello"}, obj2 = {20, "bye"};
	fun(&obj1, &obj2);
	printf("%d %d %s %s\n", obj1.a, obj2.a, obj1.s, obj2.s);
}
