#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include<sys/ioctl.h>
#include"ioctl.h"
int main()
{

        int fd,ret;
        char *arg ="HELLO WORLD";
	char str[20];
        fd = open("/dev/sathi",O_RDWR);
        if(fd < 0)
        {
                perror("open");
        }

        ret = ioctl(fd,WRITE_DATA,arg);
        if(ret== -1) {
                perror("ioctl error\n");
        }
	ret = lseek(fd,0,SEEK_SET);
	if(ret <0 ) {
		printf("error in lseek\n");
	}
        ret = ioctl(fd,READ_DATA,str);
        if(ret== -1) {
                perror("ioctl error\n");
        }
        printf("%s\n",str);
	
        close(fd);

        return 0;
}

