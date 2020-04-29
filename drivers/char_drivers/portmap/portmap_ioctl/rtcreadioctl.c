/*1.implement RTC driver with ioctl.

2.implement ioctl with supports both read write operations rtc.

3.write a test application which will read values from rtc.

4.write a test application which will write values into rtc.

note: application should take the values as command line arguments.
*/

#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include"rtc.h"
#include"ioctl.h"
#include<linux/fs.h>
#include<linux/device.h>
#include<asm/uaccess.h>

#define DIV_NAME "chr_dev"

static unsigned char CMD[6] = {DATE,MONTH,YEAR,HRS,MIN,SEC};
static dev_t mydev;
static int major;
static struct file_operations chr_fops;
static struct class *chr_class;

int myopen(struct inode *inode, struct file *file)
{
	pr_info("file opened\n");

	return 0;
}

long myioctl(struct file *file, unsigned int cmd, unsigned long arg) {

	int d,m,y,h,n,s;
	char b;
	char *val,buf[20];

	val = (char *)arg;

	if(_IOC_TYPE(cmd) != MAGIC_NUM) {
		pr_info("invalid case\n");
		return -EIO;
	}

	if(_IOC_DIR(cmd) && _IOC_READ)
		if(!access_ok(VERIFY_WRITE,(void *)arg,_IOC_SIZE(cmd)))
			return -EIO;

	if(_IOC_DIR(cmd) & _IOC_WRITE)
		if(!access_ok(VERIFY_READ,(void *)arg,_IOC_SIZE(cmd)))
			return -EIO;

	switch(cmd){
		case READ_DATE:
			READ_T(CMD[0],b);
			copy_to_user(val,&b,sizeof(b));
			break;
		case READ_MONTH:
			READ_T(CMD[1],b);
			copy_to_user(val,&b,sizeof(b));
			break;
		case READ_YEAR:
			READ_T(CMD[2],b);
			copy_to_user(val,&b,sizeof(b));
			break;
		case READ_HRS:
			READ_T(CMD[3],b);
			copy_to_user(val,&b,sizeof(b));
			break;
		case READ_MIN:
			READ_T(CMD[4],b);
			copy_to_user(val,&b,sizeof(b));
			break;
		case READ_SEC:
			READ_T(CMD[5],b);
			copy_to_user(val,&b,sizeof(b));
			break;
		case READ_ALL:
			READ_T(CMD[0],d);
			READ_T(CMD[1],m);
			READ_T(CMD[2],y);
			READ_T(CMD[3],h);
			READ_T(CMD[4],n);
			READ_T(CMD[5],s);
			sprintf(buf,"%x:%x:%x:%x:%x:%x",d,m,y,h,n,s);
			copy_to_user(val,&buf,sizeof(buf));
			break;
		default:
			return -1;
	}
	return 0;
}

int init_module(void)
{
	int minior = 0;

	chr_fops.owner = THIS_MODULE;
	chr_fops.open = myopen;
	//chr_fops.llseek = mylseek;
	chr_fops.unlocked_ioctl = myioctl;
	major = register_chrdev(major,DIV_NAME,&chr_fops);
	if(major <0) {
		pr_info("failed major no");
		return major;
	}

	pr_info("major no assigned is %d\n",major);

	mydev = MKDEV(major,minior);

	chr_class = class_create(THIS_MODULE,"SATHI");
	device_create(chr_class,NULL,mydev,NULL,"%s","sathi");

	pr_info("module inserted\n");

	return 0;
}

void cleanup_module(void) {
	unregister_chrdev(major,DIV_NAME);
	device_destroy(chr_class,mydev);
	class_destroy(chr_class);
	pr_info("module removed\n");
}

MODULE_LICENSE("GPL");

