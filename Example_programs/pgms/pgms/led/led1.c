#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<asm/uaccess.h>
#include<asm/io.h>
#define DIV_NAME "chr_dev"

#define GPBCON 0x56000010
#define GPBDAT 0x56000014
#define GPBUP  0x56000018

void *gpbcon,*gpbdat,*gpbup;
static dev_t mydev;
static int major;
static struct file_operations chr_fops;

					
static struct class *chr_class;

int myopen(struct inode *inode, struct file *file)
{

	pr_info("file opened\n");
	return 0;
}
size_t mywrite (struct file *fp, const char __user *ubuff, size_t siz, loff_t *off) {
        int val;
        copy_from_user(&val,ubuff,sizeof(ubuff));
        iowrite32((val<<7),gpbdat);
        my_timer_function(1);

        return 0;
}

int init_module(void)
{
	int minior = 0;
	
	
	gpbcon = ioremap(GPBCON,12);
	gpbdat = gpbcon + 0x04;
	gpbup = gpbcon + 0x08;

			
	iowrite32(0x00,gpbup);
	iowrite32(0x00,gpbcon);
	iowrite32((1 << 16),gpbcon);




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
	iowrite32((1<<7),gpbup);
	unregister_chrdev(major,DIV_NAME);
	device_destroy(chr_class,mydev);
	class_destroy(chr_class);

	pr_info("module removed\n");
}


MODULE_LICENSE("GPL");
