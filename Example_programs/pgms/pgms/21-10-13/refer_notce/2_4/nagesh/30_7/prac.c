#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int k,l;
	char *p = "nagesh gunna";
	char q[20];
	k = open(argv[1],O_RDWR|O_CREAT,00700);
	
	if(k < 0){
		perror("open");
		exit(1);
		}

	write(k,p,strlen(p));

	lseek(k,0,SEEK_SET);
	l = read(k,q,strlen(q));
	q[l] = '\0';
	printf("%s",q);
	close(k);
	return 0;

}
