#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{

        int fd,ret;
        char arg[20];
        char out[20];
        fd = open("/proc/rtc",O_RDONLY);
        if(fd < 0)
        {
                perror("open");
        }
	ret = read(fd,&out,sizeof(out));
	if(ret < 0) {
		printf("read error\n");
	}
	printf("%s\n",out);


        close(fd);

        return 0;
}

