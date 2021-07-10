#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>

struct thread_info *info;
struct task_struct *task;

int init_module(void)
{
	pr_info("In init\n");
	info = current_thread_info();
	pr_info("%p\n",info->task);
//	pr_info("%d\n",(info->task)->pid);
	return 0;
}

void cleanup_module(void)
{
	pr_info("In cleanup\n");
}

MODULE_AUTHOR("abc");
MODULE_DESCRIPTION("retriving info");
MODULE_LICENSE("GPL");

