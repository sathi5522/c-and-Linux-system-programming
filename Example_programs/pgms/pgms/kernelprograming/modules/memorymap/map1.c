#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int init_module(void) {
        pr_info("module inserted\n");
 	int a,i,ver,b;
	void *apic;
	int *REGSEC,*REGWIN;
	int arr[24] = {0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e};
	apic = ioremap(0xfec00000,1024);
	REGSEC = apic;
	REGWIN = (apic + 0x10);
	iowrite32(1,REGSEC);
	ver=ioread32(REGWIN);
	ver = (ver & 0x00ff0000) >> 16;
	pr_info("max irq: %x\n",ver);
	for(i =0;i < ver ;i++) {
		iowrite32(arr[i],REGSEC);
		a = ioread32(REGWIN);
		b = a;
		pr_info("the bit value %x\n",((a >> 15)&1));
		pr_info("the value of arr[i]: %x\n",(b & 0xff));

	}
        return 0;
}

void cleanup_module(void) {
        pr_info("module removed\n");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");
