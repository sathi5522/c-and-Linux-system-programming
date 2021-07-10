#include"header.h"

int init_module(void)
{
	int *regsel,*regwin,ret,res1,res,res2;
	void *ptr;
	char base = 0x10,index;
	
	REMAP(ptr);
	regsel = ptr;
	regwin = ptr+0x10;

	iowrite32(0x01,regsel);
	ret = ioread32(regwin);
	res1 = (ret & 0x00ff0000) >> 16;
	pr_info("max redir entry :%x\n",(char)res1);

	for(index = 0x00;index < res1;)
	{
		iowrite32(base,regsel);
		res = ioread32(regwin);
		res2 = (res >> 16);
		if(0x01 & res2)  pr_info("interrupt mask = 1\tinterruptvector:%x\n",(char)res);
		else            pr_info("interrupt mask = 0\tinterruptvector:%x\n",(char)res);
		index = index+0x01;
		base = base + 0x02;
	}
	return 0;
}

void cleanup_module(void)
{
	pr_info("In clean up\n");
}

MODULE_AUTHOR("MAHESH");
MODULE_DESCRIPTION("REDIRECTION TABLES");
MODULE_LICENSE("GPL");

