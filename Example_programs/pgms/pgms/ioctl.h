#ifndef VEDA
#define VEDA
#define MAGIC_NUM 'V'
#include<asm/ioctl.h>

#define GPB_CON       _IOW(MAGIC_NUM,0,unsigned int)
#define GPB_DAT      _IOR(MAGIC_NUM,1,unsigned int)
#define GPB_up       _IOWR(MAGIC_NUM,2,unsigned int)
#define MAX_CMDS        3
#endif

