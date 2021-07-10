#include <asm/ioctl.h>

#define FILL_ZERO     _IO('v',1)
//#define FILL_CHAR     _IOWR(101,2,int)
#define SET_SIZE      _IOW('v',4,unsigned int)
#define FILL_CHAR     _IOW('v',2,char)
#define GET_SIZE      _IOR('v', 3,int)
