#ifndef VEDA
#define VEDA
#include<asm/ioctl.h>

#define FILL_ZERO	/*_IO('S',1)*/ 100
#define FILL_CHAR 	/*_IOW('S',2,char)*/ 101
#define SET_SIZE	/*_IOW('S',3,unsigned int)*/ 102
#define GET_SIZE	/*_IOR('S',4,unsigned int *)*/ 103
#define MAX_CMDS	4
#endif
