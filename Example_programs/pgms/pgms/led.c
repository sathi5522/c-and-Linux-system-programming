#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include"ioctl.h"
#include<linux/fs.h>
#include<linux/device.h>
#include<asm/uaccess.h>
#define DIV_NAME "chr_dev"

#define GPBCON 0x56000010
#define GPBDAT 0x56000014
#define GPBUP  0x56000018

int *gpbcon,*gpbdat,*gpbup;
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
	int a,b,c
	char *val,buf[20];
	val = (char *)arg;
	
	gpbcon = ioremap(GPBCON,2048);
	gpbdat = gpbcon + 0x04;
	gpbup = gpbcon + 0x08;

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
		
		case GPB_CON:				
				iowrite32(0x00,gpbcon);
				b = iowrite32((1 << 16),gpbcon);
				pr_info("%d",b);
				break;
		case GPB_DAT:
				a = ioread32(gpbdat);
				copy_to_user(val,&a,sizeof(a));
				break;
		case GPB_UP:
				
				iowrite32(0x00,gpbup);
				iowrite((1<<7),gpbup);
				c = ioread32(gpbup);
				c = (c<< 7)&1;
				copy_to_user(va,&c,sizeof(c));
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
