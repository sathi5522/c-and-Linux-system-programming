#include<stdio.h>
#include<fcntl.h>

int main() {

	int fd,ret,a;
	a = 0;
	fd = open("/dev/sathi",O_RDWR);
	
	if(fd<0){
		printf("open error\n");
	}

	ret = write(fd,a,sizeof(a));
	if(ret <0) {
		printf("write error\n");
	}


	close(fd);

	return 0;
}
