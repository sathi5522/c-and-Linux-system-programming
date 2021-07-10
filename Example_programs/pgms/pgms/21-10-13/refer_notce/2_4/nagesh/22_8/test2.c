#include <stdio.h>
#include <stdlib.h>
int main()
{

	int ret;
	printf("invoking system calls");

	__asm__("movl $351,%eax");
	__asm__("int $0x80");
	__asm__("movl %eax,-4(%ebp)");

	if(ret < 0)

	exit(1);

	return 0;




}
