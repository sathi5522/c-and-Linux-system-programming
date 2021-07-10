#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{

	int fd,ret;
	int out;
	fd = open("/dev/sat4",O_RDWR);
	if(fd < 0)
	{
		perror("open");

	}
/*	ret = write(fd,&s,sizeof(int));
	if(ret < 0){
		perror("write");
	}
*/
	ret = lseek(fd,4,SEEK_SET);
	printf("lseek:%d\n",ret);
	printf("%d\n",fd);

	ret = read(fd,&out,1);
	if(ret < 0)
	{
		perror("read");
	}

	printf("month : %x\n", out);
	unlink("/dev/vdev3");
	return 0;
}
