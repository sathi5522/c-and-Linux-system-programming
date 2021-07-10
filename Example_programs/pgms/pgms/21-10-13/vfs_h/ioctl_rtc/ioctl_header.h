
#include <asm/ioctl.h>
#define MAGIC_NUMBER 'V'
#define READ_SEC     _IOR(MAGIC_NUMBER,0,unsigned int)
#define READ_MIN     _IOR(MAGIC_NUMBER,1,unsigned int)
#define READ_HOUR    _IOR(MAGIC_NUMBER,2,unsigned int)
#define READ_DATE    _IOR(MAGIC_NUMBER,3,unsigned int)
#define READ_MONTH   _IOR(MAGIC_NUMBER,4,unsigned int)
#define READ_YEAR    _IOR(MAGIC_NUMBER,5,unsigned int)
