#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int fd,ret;
	char buf[100];
	ret = getpid();

	fd = open("/proc/ret/maps",O_RDONLY);
	struct task_struct task;
	printf("%x\n",task.mm->mmap_base);
	printf("%x\n",task.mm->task_size);
		
	close(fd);	
	return 0;
}	
