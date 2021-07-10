#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc,char *argv[])
{

	DIR *dir;
	struct dirent *d;
	dir = opendir(argv[1]);
	//d = readdir(dir);
	if(dir == NULL)
		printf("opendir error");
	else {
		printf("the files in directory");
		while((d=readdir(dir)) != NULL)
			printf("%s\n",d->d_name);
	}
	closedir(dir);
	
	return 0;
}

