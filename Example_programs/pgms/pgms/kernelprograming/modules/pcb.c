#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int init_module(void) {
        printk("module inserted\n");
	struct thread_info *td;
	struct task_struct *pcb;
	td = current_thread_info();
	pcb = td->task;
	pr_info("%p\n",pcb);
	

        return 0;
}

void cleanup_module(void) {
        printk("module removed\n");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");

