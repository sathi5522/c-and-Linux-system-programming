#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int init_module(void) {
        pr_info("module inserted\n");
	int a,b;
	void *apic;
	int *REGSEC,*REGWIN,ver;
	apic = ioremap_nocache(0xfec00000,1024);
	REGSEC = apic;
	REGWIN = (apic + 0x10);
	
	iowrite32(0,REGSEC);
	a = ioread32(REGWIN);
        return 0;
}

void cleanup_module(void) {
        pr_info("module removed\n");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");
