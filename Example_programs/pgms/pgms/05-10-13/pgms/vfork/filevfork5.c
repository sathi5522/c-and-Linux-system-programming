#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
        int fd,ret;

        char buf[20];

        pid_t pid;

        fd = open("./test.file",O_RDWR);
	pid = vfork();
	 switch(pid) {
                case -1:
                        perror("fork");
                        exit(1);
                        break;
                case 0:
                        printf("child message %d\n",getpid());
			ret = read(fd,buf,sizeof(buf));
			buf[ret] = '\0';
                        printf("%s",buf);
			exit(1);
                        break;
                default:
                        printf("parent message %d\n",getpid());
                        getchar();
			break;
        }
        return 0;
}

