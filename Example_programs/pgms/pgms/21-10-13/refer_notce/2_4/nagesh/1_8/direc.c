#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	
//	struct dirent *s;
	int l;
//	DIR *p;
//	p =opendir(argv[1]);
	l =mkdir(argv[1],0777);
	printf("%d",l);

	
	
	return 0;

}
