#ifndef VEDA
#define VEDA
#define MAGIC_NUM 'V'
#include<asm/ioctl.h>

#define READ_IDEN 	_IOR(MAGIC_NUM,0,unsigned int)
#define READ_VER	_IOR(MAGIC_NUM,1,unsigned int)
#define READ_IRQ 	_IOR(MAGIC_NUM,2,unsigned int)
#define MAX_CMDS	3
#endif
