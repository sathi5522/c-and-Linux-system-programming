/* 	By default all global symbols in modules have static linkage other modules can't access such symbols
	
	modules can selectively export data symbols or function symbols into the kernel global_symbol_table.

	exporting a symbol in a module will make these symbols visible to rest of the kernel code and can be accessed by any of the kernel code

		EXPORT_SYMBOL(sysname) -> unconditional export any kernel code can access this symbol
		EXPORT_SYMBOL_GPL(sysname) -> conditional export only those parts of the kernel code which are registered with GPL license can 			access this symbol. kernel code without GPL license acn't access this symbol.
		EXPORT_SYMBOL_GPL_FUTURE(symname) -> symbol which is not GPL as of know but in future it's changed to GPL.
*/	

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
MODULE_DESCRIPTION("symbol");
MODULE_LICENSE("GPL");
