#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{

	char a[100],b[100],c[100];

	int fd,ret;

	fd = open("/dev/vdev3",O_RDWR);
	if(fd < 0){

		perror("open\n");
	}
	
	memset(a,'A',sizeof(a));
//	a[99] = '\0';
	memset(b,'B',sizeof(a)-1);
	b[99] = '\0';

	ret = write(fd,a,sizeof(a));
	printf("write_1 ret : %d\n",ret);
	ret = write(fd,b,sizeof(b));
	printf("write_2 ret : %d\n",ret);
	
/*	ret = lseek(fd,20,SEEK_SET);
	printf("seek ret : %d\n",ret);	
	ret =read(fd,c,sizeof c);
	printf("read_ret : %d\n",ret);	
	printf("%s\n",c);	
	
	ret = lseek(fd,20,SEEK_CUR);
	printf("seek ret : %d\n",ret);	
	ret =read(fd,c,sizeof c);
	printf("read_ret : %d\n",ret);	
	printf("%s\n",c);	*/

	ret = lseek(fd,-20,SEEK_END);
	printf("seek ret : %d\n",ret);	
	ret =read(fd,c,sizeof c);
	printf("read_ret : %d\n",ret);	
	printf("%s\n",c);	


	close(fd);
	return 0;



}
