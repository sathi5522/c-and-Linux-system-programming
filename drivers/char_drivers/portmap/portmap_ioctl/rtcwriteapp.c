#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include<sys/ioctl.h>
#include"ioctl.h"
#include <unistd.h>

int main(int argc,char *argv[])
{

	int fd,ret;
	char arg[20];
	char *str;
	char *token;
	int day,mon,year;

	str = argv[1];

	/*token = strtok(str,"/");
	  perror("open");
	  perror("ioctl error\n");
	  int day,mon,year,i;
	  while( token != NULL )
	  {
	  for(i = 0;i<3;i++) {
	  a[i] = atoi(token);
	  printf("array:%d\n",a[i]);
	  printf( " %s\n", token );
	  token = strtok(NULL,"/");
	  }
	  }*/

	sscanf(str,"%d/%d/%d",&day,&mon,&year);
	fd = open("/dev/sathi",O_RDWR);
	if(fd < 0)
	{
		perror("open");
	}

	ret = ioctl(fd,WRITE_DATE,day);
	if(ret== -1) {
		perror("ioctl error\n");
	}

	ret = ioctl(fd,WRITE_MONTH,mon);
	if(ret== -1) {
		perror("ioctl error\n");
	}

	ret = ioctl(fd,WRITE_YEAR,year);
	if(ret== -1) {
		perror("ioctl error\n");
	}

	ret = ioctl(fd,READ_ALL,&arg);
	if(ret== -1) {
		perror("ioctl error\n");
	}

	printf("date:%s\n",arg);

	/*ret = ioctl(fd,READ_MONTH,&arg);
	  if(ret== -1) {
	  perror("ioctl error\n");
	  }

	  printf("month:%d\n",arg);

	  ret = ioctl(fd,READ_YEAR,&arg);
	  if(ret== -1) {
	  perror("ioctl error\n");
	  }

	  printf("year:%d\n",arg);
	 */

	close(fd);
	return 0;
}

