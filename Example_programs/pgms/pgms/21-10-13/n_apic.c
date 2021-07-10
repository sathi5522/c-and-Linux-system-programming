#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/module.h>



int init_module(void)
{

	void *apic;
	int *reg_sel;
	int *reg_win,*ver;

	apic  = ioremap(0xfec00000,1024);

	reg_sel = apic;
	reg_win = apic+0x10;
	*reg_sel = *reg_sel|0x01;

//	iowrite32(0x01,reg_sel);
//	ver = ioread32(reg_win);
	pr_info("version : %x\n",*reg_win);
	
	
	return 0;




}

void cleanup_module(void)
{

	pr_info("module removed\n");
}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("APIC MODULE READING");
MODULE_LICENSE("GPL");
