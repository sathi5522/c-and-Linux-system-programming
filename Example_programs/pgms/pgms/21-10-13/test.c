#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{

	int fd,ret;
	int s = 1,out;
	fd = open("/dev/vdev3",O_RDWR);
	if(fd < 0)
	{
		perror("open");

	}
	ret = write(fd,&s,sizeof(s));
	if(ret < 0){
		perror("write");
	}

	ret = read(fd,&out,sizeof(out));
	if(fd < 0)
	{
		perror("read");
	}

	printf("sec : %x\n", out);
	unlink("/dev/vdev3");
	return 0;
}
