#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int fun(void) {
	printk("Hello World");
}

int init_module(void) {
	printk("module inserted");

	return 0;
}

void cleanup_module(void) {
	printk("module removed");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");
