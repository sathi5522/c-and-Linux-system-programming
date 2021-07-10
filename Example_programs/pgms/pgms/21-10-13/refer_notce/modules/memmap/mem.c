#include"header.h"

int init_module(void)
{
	int *regsel,*regwin,res;
	void *ptr;

	REMAP(ptr);
	regsel = ptr;
	regwin = ptr + 0x10;
	
	iowrite32(0x00,regsel);
	res = ioread32(regwin);
	
	res = res & 0x0f000000 >> 24;
	pr_info("id :%x\n",res);
	return 0;
}

void cleanup_module(void)
{
	pr_info("In cleanup\n");
}

MODULE_AUTHOR("MAHESH");
MODULE_DESCRIPTION("ID");
MODULE_LICENSE("GPL");
			
