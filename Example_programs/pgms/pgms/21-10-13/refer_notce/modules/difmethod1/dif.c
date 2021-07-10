#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>

static int value;
int init_module(void)
{
	pr_info("module inserted\n");
	value = 100;
	return 0;
}

void cleanup_module(void)
{
	pr_info("module removed\n");
}

EXPORT_SYMBOL_GPL(value);
MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("DIFFERENCE OF TWO");
MODULE_LICENSE("GPL");
	
