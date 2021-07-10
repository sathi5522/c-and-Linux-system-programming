#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
//#define MAX 300
//#define MIN 0
#define NAME "vdev1"


static dev_t mydev;
struct file_operations fops;
struct cdev *mycdev;

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
//	mydev = MKDEV(MAX,MIN);
//	register_chrdev_region(mydev,1,NAME);
	alloc_chrdev_region(&mydev,0,1,NAME);
	fops.owner = THIS_MODULE;
	fops.open = myopen;	
	fops.read = myread;
	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,1);
	pr_info("module inserted\n");
	return 0;
}




void cleanup_module(void)
{
	
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
