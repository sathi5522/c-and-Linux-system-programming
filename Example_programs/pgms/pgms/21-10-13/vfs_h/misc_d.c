#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
//#define MAX 300
//#define MIN 0
#define NAME "vdev1"

dev_t mydev;
static struct miscdevice vdevmisc;
struct file_operations fops1;
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
//	mydev = MKDEV(,MIN);
//	register_chrdev_region(mydev,1,NAME);
//	alloc_chrdev_region(&mydev,0,1,NAME);


	fops1.owner = THIS_MODULE;
	fops1.open = myopen;	
	
	fops1.read = myread;
	vdevmisc.minor = MISC_DYNAMIC_MINOR;
        vdevmisc.name =  NAME;
	vdevmisc.fops = &fops1;

	mydev = MKDEV(10,vdevmisc.minor);
	misc_register(&vdevmisc);
//	mycdev = cdev_alloc();
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
	misc_deregister(&vdevmisc);
	device_destroy(veda_class,mydev);
	class_destroy(veda_class);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
