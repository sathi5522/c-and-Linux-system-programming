#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "ioctl_header.h"
#include <sys/ioctl.h>
int main()
{

	int fd,ret,size;
	char out[100];
	fd = open("/dev/vdev3",O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return 0;
	}

/*checking with fill zero */

	ret = ioctl(fd,FILL_ZERO);
	if(ret < 0)
	{
		perror("ioctl\n");
	}

	lseek(fd,0,SEEK_SET);

	ret = read(fd,out,sizeof(out));	
	printf("%s\n",out);

	lseek(fd,0,SEEK_SET);





/* checking fill char */
	ret = ioctl(fd,FILL_CHAR,'A');
	if(ret < 0)
	{
		perror("ioctl\n");
	}
	ret = read(fd,out,sizeof(out));	
	printf("%s\n",out);
	
/*checking get size */

	ret = ioctl(fd,GET_SIZE,&size);
	if(ret < 0)
	{
		perror("ioctl\n");
	}
	printf("%d\n",size);
/*checkin set size */


	ret = ioctl(fd,SET_SIZE,3);/*increment kernel buffer with 3 */
	ret = ioctl(fd,GET_SIZE,&size);
	if(ret < 0)
	{
		perror("ioctl\n");
	}
	printf("%d\n",size);

/************/

	close("/dev/vdev3");
	return 0;
}
