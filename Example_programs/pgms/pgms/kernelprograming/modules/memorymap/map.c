/* memory map example: 82093AA I/O ADVANCED PROGRAMMABLE INTERRUPT CONTROLLER (IOAPIC) */


#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int init_module(void) {
        pr_info("module inserted\n");
	int a,b;
	void *apic;
	int *REGSEC,*REGWIN,ver;
	apic = ioremap/*_nocache*/(0xfec00000,1024);
	REGSEC = apic;
	REGWIN = (apic + 0x10);
	pr_info("register select:%#x\n",REGSEC);
	pr_info("register window:%#x\n",REGWIN);
	pr_info("register select:%#x\n",((*REGSEC) & 0xff));
	pr_info("register window:%#x\n",((*REGWIN) & 0xffffffff));
	
	iowrite32(0,REGSEC);
	a = ioread32(REGWIN);
	pr_info("identification:%x\n",(a & 0x0f000000) >> 23);
/*	iowrite32(1,REGSEC);
	ver=ioread32(REGWIN);
	b = ver;
	pr_info("ver =%x\n",b & 0xff);	
	pr_info("max irq: %x\n",(ver & 0x00ff0000) >> 16);
  */      return 0;
}

void cleanup_module(void) {
        pr_info("module removed\n");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");
