#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int val = 100;

int my_init(void)
{
	printk(" example module inserted val: %d\n", val);
	return 0;
}

void my_exit(void)
{

	printk(" Example module exited\n");
}

module_init(my_init);
module_exit(my_exit);

EXPORT_SYMBOL_GPL(val);
MODULE_AUTHOR("satheesh");
//MUDULE_DESCRIPTION("examplemodule");
MODULE_LICENSE("GPL");
