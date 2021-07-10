#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
//#define MAX 300
#define MIN 0
#define NAME "vdev1"


static dev_t mydev;
static int major;
struct file_operations fops;
//struct cdev *mycdev;
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
//	register_chrdev_region(mydev,1,NAME);
//	alloc_chrdev_region(&mydev,0,1,NAME);
	fops.owner = THIS_MODULE;
	fops.open = myopen;	
	fops.read = myread;
	 major = register_chrdev(0,NAME,&fops);
//	mycdev = cdev_alloc();
	mydev = MKDEV(major,MIN);
//	cdev_init(mycdev,&fops);
//	cdev_add(mycdev,mydev,1);

	veda_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(veda_class,NULL,mydev,NULL,"%s","vdev3");



	pr_info("module inserted\n");
	return 0;
}




void cleanup_module(void)
{
	
//	cdev_del(mycdev);
//	unregister_chrdev_region(mydev,1);
	unregister_chrdev(major,NAME);
	device_destroy(veda_class,mydev);
	class_destroy(veda_class);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
