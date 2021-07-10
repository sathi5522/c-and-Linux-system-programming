#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	struct stu {
		char name[20];
		int no;
		char gen;
	};
	int fd,ret,i;
	struct stu s[3] ={{"abc",1,'m'},{"xyz",2,'f'},{"wqr",3,'m'}};
	struct stu rs;
	if(argc == 1) {
		printf("error");
		exit(1);
	}

	fd = open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd<0) {
		perror("open");
		exit(2);
	}
	printf("the new file descriptor %d\n",fd);
	ret = write(fd,s,sizeof(struct stu)*3);
	if(ret<0) {
		perror("write");
		exit(3);
	}
	printf("%d bytes written to the file %s\n",ret,argv[1]);


	for(i=0;i<3;i++){
		if((i%2) == 0) {
		lseek(fd,i * sizeof(struct stu),SEEK_SET);
		ret = read(fd,&rs,sizeof(struct stu ));
		printf("%s\n",rs.name);
		printf("%d\n",rs.no);
		printf("%c\n",rs.gen);
		}
	}
	close(fd);
	return 0;
}
