#include<stdio.h>
#include<fcntl.h>

int main() {
	int fd,ret;
	//char mydata[100] = "hai welcome to india";
	char data[20];

	fd  = open("/proc/mytstproc",O_RDWR);
	if(fd < 0) {
		printf("open error\n");
	}
	/*ret  = write(fd,mydata,sizeof(mydata));
	if(ret<0) {
		printf("write error\n");
	}*/
	ret = read(fd,data,sizeof(data));
	if(ret <0) {
		printf("read error");
	}
	
	printf("%s\n",data);

	close(fd);
	
	return 0;
}
