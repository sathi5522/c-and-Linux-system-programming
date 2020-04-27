#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

/*indirect access*/
static int *ptr;

/*direct access*/
//extern int val;

int my_init(void)
{
	/*indirect access*/
	ptr = (int *) __symbol_get("val");
	if(ptr) {
		*ptr = 800;
		__symbol_put("val");
		printk("symbol module inserted val: %d \n",*ptr);
		return 0;
	}
	else {
		printk("symbol not available\n");
		return -1;
	}
	/*direct access*/	
	//printk("symbol module inserted val: %d \n",val);
	//return 0;
}

void my_exit(void)
{
	printk("symbol module exited\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("satheesh");
MODULE_LICENSE("GPL");
