#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

static int value;

int init_module(void)
{
	pr_info("module is inserted\n");
	value = 10;
	return 0;
}

void cleanup_module(void)
{
	pr_info("module removed\n");
}

EXPORT_SYMBOL(value);
MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("DIFF OF TWO INTEGERS");
MODULE_LICENSE("GPL");
