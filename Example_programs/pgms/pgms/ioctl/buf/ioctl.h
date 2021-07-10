
#ifndef VEDA
#define VEDA
#define MAGIC_NUM 'V'
#include<asm/ioctl.h>

#define WRITE_DATA      _IOW(MAGIC_NUM,0,char *)
#define READ_DATA      _IOR(MAGIC_NUM,1,char *)
#define MAX_CMDS        2
#endif
