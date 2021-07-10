#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include "rtc_header.h"
#include "ioctl_header.h"
#define  DEV_NAME  "rtc_driver"

static dev_t  mydev;
static int    major = 10,ret,data;
static struct miscdevice vdevmisc;
static struct file_operations fops;
static struct class *veda_class;
static int a[6] = {SEC,MIN,HOUR,DATE,MONTH,YEAR};



int rtc_open(struct inode * node, struct file *file)
{
	pr_info("rtc_file opened\n");
	
	return 0;
}

int rtc_release(struct inode *node, struct file *file)
{

	pr_info("rtc_file closed\n");
	return 0;
}

long rtc_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int *alt = (int *)arg;
	
	if( _IOC_TYPE(cmd) != MAGIC_NUMBER)
	return -ENOTTY;

	if( _IOC_DIR(cmd) & _IOC_READ){
		if(!access_ok(VERIFY_WRITE,arg,_IOC_SIZE(cmd)))
		return -EIO;
	}
	switch(cmd){

		case READ_SEC   :  READ_T(a[0],data);
				   copy_to_user(alt,&data,sizeof(data));		
				   break;

		case READ_MIN   :  READ_T(a[1],data);
				   copy_to_user(alt,&data,sizeof(data));
				   break;
		
		case READ_HOUR  :  READ_T(a[2],data);
				   copy_to_user(alt,&data,sizeof(data));
				   break;


		case READ_DATE  :  READ_T(a[3],data);
				   copy_to_user(alt,&data,sizeof(data));
				   break;


		case READ_MONTH :  READ_T(a[4],data);
				   copy_to_user(alt,&data,sizeof(data));
				   break;

		case READ_YEAR  :  READ_T(a[5],data);
				   copy_to_user(alt,&data,sizeof(data));
				   break;

		default  :  return -EIO;
	}
	
	


	pr_info("rtc_ioctl\n");
	return 0;

}





int init_module(void)
{
	fops.owner           =  THIS_MODULE;
	fops.open            =  rtc_open;
	fops.release         =  rtc_release;
	fops.unlocked_ioctl  =  rtc_ioctl;
		   


	vdevmisc.minor = MISC_DYNAMIC_MINOR;
	vdevmisc.fops  = &fops;
	vdevmisc.name  = DEV_NAME;
		   
	
	ret =  misc_register(&vdevmisc);

	if(ret < 0){
		printk(KERN_ERR"miscdevice registration failed\n");
		return -EIO;
	}



	pr_info("module inserted\n");
	return 0;
}

void cleanup_module(void)
{     

	misc_deregister(&vdevmisc);
	pr_info("module removed\n");

}






MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("IMPLENTING RTC WITH IOCTL");
MODULE_LICENSE("GPL");
