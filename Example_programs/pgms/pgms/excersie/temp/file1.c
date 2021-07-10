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
	struct stu rs[3];
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
	lseek(fd,0,SEEK_SET);
	ret = read(fd,rs,sizeof(struct stu )*3);

//	rs[0].name[ret] = '\0';
for(i=0;i<3;i++){
	printf("%s\n",rs[i].name);
	printf("%d\n",rs[i].no);

	//rs[0].gen[ret] = '\0';
	printf("%c\n",rs[i].gen);
}
	close(fd);
	return 0;
}
