#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int fd,ret;
	char buf[100];

	fd = open("/dev/bufb",O_RDWR);
	memset(buf,'C',sizeof(buf)-1);
//	buf[99] = '\0';
	ret = write(fd,buf,sizeof(buf));
	printf("%d\n",ret);
	
	memset(buf,'D',sizeof(buf)-1);
	buf[99] = '\0';
	ret = write(fd,buf,sizeof(buf));
	printf("%d\n",ret);
	
	memset(buf,0,sizeof(buf));
	ret=lseek(fd,10,SEEK_SET);
	printf("%d\n",ret);
	ret = read(fd,buf,sizeof(buf));
	printf("%s%d\n",buf,ret);

	ret=lseek(fd,20,SEEK_END);
	printf("%d\n",ret);
//	memset(buf,0,sizeof(buf));

	ret = read(fd,buf,sizeof(buf));
	printf("%s%d\n",buf,ret);
	close(fd);
	return 0;
}	
