/* implement apic driver with ioctl which reads identification number,version and number of irqlines*/

#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include"ioctl.h"
#include<linux/fs.h>
#include<linux/device.h>
#include<asm/uaccess.h>

#define DIV_NAME "chr_dev"

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

	int a,ver;
	int *val;
	void *apic;
	int *REGSEC,*REGWIN;

	val = (int *)arg;

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

	apic = ioremap(0xfec00000,1024);
	REGSEC = apic;
	REGWIN = (apic + 0x10);

	switch(cmd) {
		case READ_IDEN:
			iowrite32(0x00,REGSEC);
			a = ioread32(REGWIN);
			a = (a & 0x0f000000) >> 23;
			copy_to_user(val,&a,sizeof(a));
			break;

		case READ_VER:
			iowrite32(0x01,REGSEC);
			ver=ioread32(REGWIN);
			ver = ver & 0xff;
			copy_to_user(val,&ver,sizeof(ver));
			break;

		case READ_IRQ:
			iowrite32(0x01,REGSEC);
			ver=ioread32(REGWIN);
			ver = (ver & 0x00ff0000) >> 16;
			copy_to_user(val,&ver,sizeof(ver));
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
