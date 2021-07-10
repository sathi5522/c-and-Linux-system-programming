#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include<linux/slab.h>
#include "rtc.h"
#include"ioctl.h"
#define NAME "vdev1"


struct pri_data  {
	char *kbuf;
	int size;
};
struct pri_data pri;
static dev_t mydev;
struct file_operations fops;
struct cdev *mycdev;
struct class *veda_class;
int myopen(struct inode *inode, struct file *file)
{

	pr_info("file opened\n");
	return 0;
}

ssize_t myread(struct file *file, char __user *usr, size_t val, loff_t *var)
{

	copy_to_user(usr,&pri.kbuf,4096);

        pr_info("file read\n");
	return 0;

}




ssize_t mywrite (struct file *file, const char __user *usr , size_t val, loff_t *var)
{
                pr_info("file write\n");
	
	return 0;


}
long myioctl (struct file *file, unsigned int cmd, unsigned long arg) {
	//char *buf;
	int *size;
	switch(cmd) {
		case FILL_ZERO:
				memset(pri.kbuf,0,pri.size);
				pr_info("FILL_ZERO is fill zeros\n");
				break;
		case FILL_CHAR:
				memset(pri.kbuf,arg,pri.size);
				pr_info("FILL_CHAR is fill char\n");
				break;
		case SET_SIZE:
				pri.size = arg;
				pri.kbuf = krealloc(pri.kbuf,pri.size,GFP_KERNEL);
				if(!pri.kbuf)
					return -1;
				pr_info("SET_SIZE is set the size\n");
				break;
		case GET_SIZE:
				size = (int *)arg;
				copy_to_user(size,&pri.size,pri.size);
				pr_info("GET_SIZE is get the size\n");
				break;
		default:
			return -1;
	}

	return 0;
	
}
int myrelease(struct inode *inode,struct file *file)
{



	pr_info("file closed\n");

	return 0;
}

int init_module(void)
{
	pri.size = 4096;
	pri.kbuf = kmalloc(pri.size,GFP_KERNEL);
	if(!pri.kbuf)
		return -1;

	alloc_chrdev_region(&mydev,0,1,NAME);
	
	fops.owner = THIS_MODULE;
	fops.open = myopen;	
	fops.read = myread;
	fops.write = mywrite;
	fops.release = myrelease;
	//fops.llseek = mylseek;
	fops.unlocked_ioctl = myioctl;

	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,1);

	veda_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(veda_class,NULL,mydev,NULL,"%s%d","sat",4);



	pr_info("module inserted\n");
	return 0;
}




void cleanup_module(void)
{
	kfree(pri.kbuf);
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);
	device_destroy(veda_class,mydev);
	class_destroy(veda_class);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("sathi");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
