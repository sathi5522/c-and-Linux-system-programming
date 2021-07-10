#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	struct stat s;
	
	int k,l;
	k = open(argv[1],O_RDWR|O_CREAT,00700);

	l = stat(argv[1],&s);

	printf("total size :%u\n user id : %u\n group id : %u\n",s.st_size,s.st_uid,s.st_gid);
	
	//	if(S_IRWXU&s.st_mode)
	//	printf("user : rwx");
		 if(S_IWUSR&s.st_mode)
		printf("user : w");
		 if(S_IRUSR&s.st_mode)
		printf("user : r");
		if(S_IXUSR&s.st_mode) 
		printf("user :x");
		if(S_IRWXG&s.st_mode)
		printf("group : rwx");
		if(S_IWGRP&s.st_mode)
		printf("group : w");
		 if(S_IRGRP&s.st_mode)
		printf("group : r");
		if(S_IXGRP&s.st_mode)
		printf("gruop :x");
		if(S_IRWXO&s.st_mode)
		printf("other : rwx");
		 if(S_IWOTH&s.st_mode)
		printf("other : w");
		 if(S_IROTH&s.st_mode)
		printf("other : r");
		 if(S_IXOTH&s.st_mode) 
		printf("other : x");

	close(k);
	return 0;





}
