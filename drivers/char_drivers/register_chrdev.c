#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define MIN 0

#define NAME "my_cdev"

static dev_t mydev;
static int major;
struct file_operations fops;
struct class *veda_class;

int myopen(struct inode *inode, struct file *file)
{
	pr_info("file opened\n");

	return 0;
}

ssize_t myread(struct file *file, char __user *usr, size_t val, loff_t *var)
{
	pr_info("file read\n");

	return 0;
}

int init_module(void)
{
	fops.owner = THIS_MODULE;
	fops.open = myopen;
	fops.read = myread;

	major = register_chrdev(0,NAME,&fops);
	mydev = MKDEV(major,MIN);
	veda_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(veda_class,NULL,mydev,NULL,"%s%d","my_cdev",1);

	pr_info("module inserted\n");

	return 0;
}

void cleanup_module(void)
{
	unregister_chrdev(major,NAME);
	device_destroy(veda_class,mydev);
	class_destroy(veda_class);

	pr_info("module removed\n");
}

MODULE_AUTHOR("SATHI");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
