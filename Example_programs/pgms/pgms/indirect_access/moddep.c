#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

static int *ptr;

int myinit(void)
{
	ptr = (int *)__symbol_get("variable");

	if(ptr){
		*ptr = 1000;
		pr_info("moddep is inserted\n");
		pr_info("variable = %d", *ptr);
		__symbol_put("variable");
		return 0;
	}
	else{
		pr_info("variable not found\n");
		return -1;
	}

}

void myexit(void)
{
	pr_info("moddep is removed\n");
}

module_init(myinit);
module_exit(myexit);

MODULE_AUTHOR("KALAM");
MODULE_DESCRIPTION("MODDEP");
MODULE_LICENSE("GPL");
