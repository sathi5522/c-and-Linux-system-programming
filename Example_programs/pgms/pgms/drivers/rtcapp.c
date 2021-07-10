#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{

	int fd,ret,s = 0x01;
	char out[20];
	fd = open("/dev/sat4",O_RDWR);
	if(fd < 0)
	{
		perror("open");

	}
/*	ret = lseek(fd,5,SEEK_SET);
	ret = write(fd,&s,1);
	if(ret < 0){
		perror("write");
	}*/

	ret = lseek(fd,6,SEEK_SET);
	printf("lseek:%d\n",ret);
	printf("%d\n",fd);

	ret = read(fd,&out,sizeof(out));
	if(ret < 0)
	{
		perror("read");
	}

	printf("%s\n",out);
	unlink("/dev/vdev3");
	return 0;
}
