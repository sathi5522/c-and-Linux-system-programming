#include <stdio.h>
#include <stdlib.h>
int main()
{

	int ret;
	
	printf("invoking system call\n");
	
	__asm__("movl $349,%eax");
	__asm__("int $0x80");
	__asm__("movl %eax,-4(%ebp)");

	if(ret < 0)
		exit(1);

	return 0;


}
