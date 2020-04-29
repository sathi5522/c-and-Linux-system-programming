#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fd,ret,s;
	char out[20],str[1];

	strcpy(str, argv[1]);
	fd = open("/dev/sat4",O_RDWR);
	if(fd < 0)
	{
		perror("open");
	}

	sscanf(str,"%d",&s);

	ret = lseek(fd,5,SEEK_SET);

	ret = write(fd,&s,1);
	if(ret < 0){
		perror("write");
	}

	ret = lseek(fd,6,SEEK_SET);
	printf("lseek:%d\n",ret);
	printf("%d\n",fd);
	ret = read(fd,&out,sizeof(out));
	if(ret < 0)
	{
		perror("read");
	}

	printf("%s\n",out);
	close(fd);
	//unlink("/dev/vdev3");

	return 0;

}
