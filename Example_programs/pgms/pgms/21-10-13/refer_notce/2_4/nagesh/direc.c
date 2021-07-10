#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	
	struct  dirent *s;
	DIR *p;
	int l;
	p =opendir(argv[1]);
	
	while(1){
	s =  readdir(p);
	if(s == NULL)
	break;
	printf("%d\t %d \t %hd\t %c\t %s \n",s-> d_ino,s -> d_off, s -> d_reclen, s -> d_type,s -> d_name);
	}
	

	closedir(p);
	
	return 0;

}
