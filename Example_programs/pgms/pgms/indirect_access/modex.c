#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

static int variable;

int myinit(void)
{
	variable = 100;
	pr_info("modex is inserted\n");
	pr_info("variable = %d\n", variable);	

	return 0;
}

void myexit(void)
{
	pr_info("modex is removed\n");
}

module_init(myinit);
module_exit(myexit);

EXPORT_SYMBOL_GPL(variable);

MODULE_AUTHOR("KALAM");
MODULE_DESCRIPTION("MODEX");
MODULE_LICENSE("GPL");
