#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int fd;
	char buf[25];
	fd = open("/dev/vdev",O_RDONLY);
	perror("open");
	read(fd,buf,sizeof(buf));
	perror("read");
	return 0;
}
