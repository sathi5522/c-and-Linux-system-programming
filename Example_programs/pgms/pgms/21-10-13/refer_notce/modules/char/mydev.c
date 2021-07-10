#include<linux/version.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#define DRIVER_NAME "mydriver"

struct file_operations fops;
struct cdev *mycdev;
dev_t mydev;

int myopen(struct inode *inode, struct file *file)
{
	pr_info("In myopen\n");
	return 0;
}

ssize_t myread(struct file *file, char __user *var, size_t size, loff_t *val)
{
	pr_info("In myread\n");
	return 0;
}

int init_module(void)
{
	pr_info("Inserted\n");
	fops.owner = THIS_MODULE;
	fops.open  = myopen;
	fops.read  = myread;
	mydev = MKDEV(300,0);
	register_chrdev_region(mydev,1,DRIVER_NAME);
		
	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	
	cdev_add(mycdev,mydev,1);
	return 0;
}

void cleanup_module(void)
{	
	pr_info("removed\n");
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);
}

MODULE_AUTHOR("MAHESH");
MODULE_DESCRIPTION("char driver");
MODULE_LICENSE("GPL");	
