#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int k,l;

	struct stu{
		int age;
		char name[20];
		}st = {12,"vicky"},stp;






	k = open(argv[1],O_RDWR|O_CREAT,00700);
	
	if(k < 0){
		perror("open");
		exit(1);
		}

	write(k,&st,sizeof(st));

	lseek(k,0,SEEK_SET);
	l = read(k,&stp,sizeof(stp));

	printf("%s",stp.name);
	close(k);
	return 0;

}
