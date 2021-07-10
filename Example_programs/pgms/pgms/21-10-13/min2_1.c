#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
//#define MAX 300
//#define MIN 0
#define NAME "vdev1"


static dev_t mydev,mydev_1;
static int major;
struct file_operations fops;
struct cdev *mycdev;
struct class *veda_class;

int myopen(struct inode *inode, struct file *file)
{
	
	pr_info("min :%d",MINOR(inode->i_rdev));
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
	alloc_chrdev_region(&mydev,0,2,NAME);
	major = MAJOR(mydev);
	mydev_1 = MKDEV(major,1);
	fops.owner = THIS_MODULE;
	fops.open = myopen;	
	fops.read = myread;
	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,2);
	
	veda_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(veda_class,NULL,mydev,NULL,"%s","vdev3");
	device_create(veda_class,NULL,mydev_1,NULL,"%s","vdev2");



	pr_info("module inserted\n");
	return 0;
}




void cleanup_module(void)
{
	
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,2);
	device_destroy(veda_class,mydev);
	device_destroy(veda_class,mydev_1);
	class_destroy(veda_class);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
