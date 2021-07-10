#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include<sys/ioctl.h>
#include"ioctl.h"
int main()
{

        int fd,ret;
        int arg;
        fd = open("/dev/sathi",O_RDWR);
        if(fd < 0)
        {
                perror("open");
        }

        ret = ioctl(fd,READ_IRQ,&arg);
        if(ret== -1) {
                perror("ioctl error\n");
        }
        printf("%x\n",arg);

        close(fd);

        return 0;
}

