#ifndef VEDA

#define VEDA

#define MAGIC_NUM 'V'

#include<asm/ioctl.h>

#define READ_DATE _IOR(MAGIC_NUM,0,unsigned int)

#define READ_MONTH _IOR(MAGIC_NUM,1,unsigned int)

#define READ_YEAR _IOR(MAGIC_NUM,2,unsigned int)

#define READ_HRS _IOR(MAGIC_NUM,3,unsigned int)

#define READ_MIN _IOR(MAGIC_NUM,4,unsigned int)

#define READ_SEC _IOR(MAGIC_NUM,5,unsigned int)

#define READ_ALL _IOR(MAGIC_NUM,6,unsigned int)

#define WRITE_DATE _IOW(MAGIC_NUM,7,unsigned int)

#define WRITE_MONTH _IOW(MAGIC_NUM,8,unsigned int)

#define WRITE_YEAR _IOW(MAGIC_NUM,9,unsigned int)

#define WRITE_HRS _IOW(MAGIC_NUM,10,unsigned int)

#define WRITE_MIN _IOW(MAGIC_NUM,11,unsigned int)

#define WRITE_SEC _IOW(MAGIC_NUM,12,unsigned int)

//#define WRITE_ALL _IOW(MAGIC_NUM,13,unsigned int)

#define MAX_CMDS 13

#endif

