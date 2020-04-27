#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/moduleparam.h>

static int val = 100;
static int l = 200;

module_param(val, int, S_IRUGO);
module_param(l, int, S_IRUGO|S_IWUSR);
int my_init(void)
{
	printk(" module param inserted val: %d %d\n", val, l);
	return 0;
}

void my_exit(void)
{

	printk(" module param exited\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("satheesh");
MODULE_PARM_DESC(val, "INITALISE val");
//MUDULE_DESCRIPTION("examplemodule");
MODULE_LICENSE("GPL");
