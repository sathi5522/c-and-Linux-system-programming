#include"header.h"

int init_module(void)
{
	int *regsel,*regwin,ret,res1;
	void *ptr;
	char res;

	REMAP(ptr);	
	regsel = ptr;
	regwin = ptr+0x10;
	
	iowrite32(0x01,regsel);
	ret = ioread32(regwin);
		
	res1 = ret & 0x000000ff;
	res = res1;
	pr_info("version :%x\n",res);
	
	ret = (ret & 0x00ff0000) >> 16;
	pr_info("max :%x\n",(char)ret);
	return 0;
}

void cleanup_module(void)
{
	pr_info("In cleanup\n");
}

MODULE_AUTHOR("MAHESH");
MODULE_DESCRIPTION("VERSION");
MODULE_LICENSE("GPL");
