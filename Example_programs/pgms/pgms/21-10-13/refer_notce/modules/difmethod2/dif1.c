#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>

static int *ptr;

int init_module(void)
{
	ptr = (int *) __symbol_get("value");
	if(ptr)
	{
		pr_info("module inserted\n");
		*ptr = 500;
		__symbol_put("value");
		return 0;
	}
	else
	{
		pr_err("symbol invalid\n");
		pr_info("value :%d\n",value);
		return 0;
	}
}

void cleanup_module(void)
{
	pr_info("module removed\n");
}

MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("DIF OF TWO INTEGERS");
MODULE_LICENSE("GPL");
