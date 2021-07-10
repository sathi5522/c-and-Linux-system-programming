#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
static int c;
int sum(int a,int b) {
	c = a + b;
	return c;
}

int init_module(void) {
	printk("module inserted\n");
	printk("insert: c=%d\n",c);
	return 0;
}

void cleanup_module(void) {
	printk("remove: c=%d\n",c);
	printk("module removed\n");
}
EXPORT_SYMBOL_GPL(c);
EXPORT_SYMBOL_GPL(sum);
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");
