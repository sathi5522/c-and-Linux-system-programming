#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include "rtc_header.h"
#define NAME "vdev1"

static int command[7] = {SEC,MIN,HRS,DAY,DATE,MONTH,YEAR};
static int msg,index;
static int date,month,year,hour,min,sec;
static char cal[18];
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
	copy_to_user(usr,&msg,val);
	pr_info("file read\n");
	return 0;

}



ssize_t mywrite (struct file *file, const char __user *usr , size_t val, loff_t *var)
{

	copy_from_user(&index,usr,val);
	READ_T(command[index],msg);
	if(index == 7){

	READ_T(command[0],sec);
	READ_T(command[1],min);
	READ_T(command[2],hour);
	READ_T(command[4],date);
	READ_T(command[5],month);
	READ_T(command[6],year);
	
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
//	mydev = MKDEV(MAX,MIN);
//	register_chrdev_region(mydev,1,NAME);
	alloc_chrdev_region(&mydev,0,1,NAME);
	
	fops.owner = THIS_MODULE;
	fops.open = myopen;	
	fops.read = myread;
	fops.write = mywrite;
	fops.release = myrelease;

	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,1);

	veda_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(veda_class,NULL,mydev,NULL,"%s","vdev3");



	pr_info("module inserted\n");
	return 0;
}




void cleanup_module(void)
{
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);
	device_destroy(veda_class,mydev);
	class_destroy(veda_class);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
