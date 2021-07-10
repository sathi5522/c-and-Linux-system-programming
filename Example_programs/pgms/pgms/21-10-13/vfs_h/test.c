#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{

	int fd,ret;
	int out;
	fd = open("/dev/vdev3",O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return 0;
	}
	
	ret = lseek(fd,1,SEEK_SET);
	printf("ret = %d\n",ret);

	ret = read(fd,&out,sizeof(int));
	if(ret < 0)
	{
		perror("read");
	}

	printf("yr : %x\n", out);
	unlink("/dev/vdev3");
	return 0;
}
