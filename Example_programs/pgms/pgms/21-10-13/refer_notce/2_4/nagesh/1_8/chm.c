#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	int l;
	l = chmod(argv[1],S_IRUSR);
	printf("%d",l);

	return 0;


}
