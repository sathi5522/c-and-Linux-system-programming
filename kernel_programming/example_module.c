#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int my_init(void)
{
	printk(" example module inserted\n");
	return 1;
}

void my_exit(void)
{

	printk(" Example module exited\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("satheesh");
//MUDULE_DESCRIPTION("examplemodule");
MODULE_LICENSE("GPL");
