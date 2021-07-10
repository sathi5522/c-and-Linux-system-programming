#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct data{

	char msg[100];
	int len;
};
int main()
{


	int fd;
	int i = 0;
	struct data st[10],(*p)[10];
	 

	strcpy(st[0].msg, "nagesh");
	st[0].len = strlen(st[0].msg);

	strcpy(st[1].msg, "raju");
	st[1].len = strlen(st[1].msg);

	strcpy(st[2].msg, "kamesh");
	st[2].len = strlen(st[2].msg);

	strcpy(st[3].msg, "krishna");
	st[3].len = strlen(st[3].msg);

	strcpy(st[4].msg, "ranveer");
	st[4].len = strlen(st[4].msg);

	strcpy(st[5].msg, "nitin");
	st[5].len = strlen(st[5].msg);

	strcpy(st[6].msg, "pavan");
	st[6].len = strlen(st[6].msg);

	strcpy(st[7].msg, "mahesh");
	st[7].len = strlen(st[7].msg);

	strcpy(st[8].msg, "ntr");
	st[8].len = strlen(st[8].msg);

	strcpy(st[9].msg, "prabhas");
	st[9].len = strlen(st[9].msg);

	fd = open("records.txt", O_RDWR,00700);

	p = mmap(NULL,sizeof(st),PROT_WRITE|PROT_EXEC,MAP_SHARED,fd,0);

	if(!p){
		perror( "mmap");
		exit(1);
		}

	close(fd);

	for(i =0; i < 10; i++){

	strcpy((*p)[i].msg, st[i].msg);	
	
	printf("%d\n",(*p)[i].len );	
	}	

	
	

	munmap(p,sizeof(st));




	return 0;
}
