#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/moduleparam.h>
#include<linux/interrupt.h>

/* check shared interrupt number in /proc/interrupts
	cat /proc/interrupts
*/
#define SHARED_IRQ 9

static int irq = SHARED_IRQ;
static int my_dev_id, irq_counter = 0;

module_param(irq, int, S_IRUGO);

static irqreturn_t my_interrupt(int irq, void *dev_id)
{
	irq_counter++;
	printk(KERN_INFO"In the ISR : counter = %d \n", irq_counter);
	return IRQ_NONE;

}
int my_init(void)
{
	if(request_irq(irq, my_interrupt, IRQF_SHARED, "my_interrupt", &my_dev_id))
		return -1;
	printk(KERN_INFO"Successfully loaded ISR handler \n");
	return 0;
}

void my_exit(void)
{
	synchronize_irq(irq);
	free_irq(irq, &my_dev_id);

	printk(KERN_INFO"successfully unloaded ISR\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("satheesh");
MODULE_PARM_DESC(val, "ISR");
MODULE_DESCRIPTION("ISR handler");
MODULE_LICENSE("GPL");
