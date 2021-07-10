#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include"ioctl.h"
#include<linux/fs.h>
#include<linux/device.h>
#include<asm/uaccess.h>
#include<linux/slab.h>
#define DIV_NAME "chr_dev"
#define BUF_SIZE 4096

static dev_t mydev;
static int major;
static struct file_operations chr_fops;
static struct class *chr_class;
static char *kbuf;

int myopen(struct inode *inode, struct file *file)
{

        pr_info("file opened\n");
        return 0;
}

loff_t mylseek(struct file *fip, loff_t length, int num)
{
	loff_t offset;

	offset = fip->f_pos;

	switch(num) {
		case 0: offset = length;
			break;
		case 1: offset = (offset + length);
			break;
		case 2: offset = offset + length;
			break;
		default: pr_info("error with offset\n");
			break;
	};
	if(offset < 0 || offset > 4096)
		return EIO;

	fip->f_pos = offset;

	return offset;
}

long myioctl(struct file *file, unsigned int cmd, unsigned long arg) {

        char *val;
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

	switch(cmd) {
	
		case WRITE_DATA:
			copy_from_user(kbuf,val,strlen(val)+1);
			pr_info("%s\n",kbuf);
			break;
		case READ_DATA:
			copy_to_user(val,kbuf,20);
			break;
		default:
			return -1;
	}
	
	return 0;
}

int init_module(void)
{
        int minior = 0;
	kbuf = kmalloc(BUF_SIZE,GFP_KERNEL);
	if(!kbuf) {
		pr_info("error in allocating size\n");
		return -1;
	}
        chr_fops.owner = THIS_MODULE;
        chr_fops.open = myopen;
        chr_fops.llseek = mylseek;
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
	kfree(kbuf);
        unregister_chrdev(major,DIV_NAME);
        device_destroy(chr_class,mydev);
        class_destroy(chr_class);

        pr_info("module removed\n");
}


MODULE_LICENSE("GPL");
                       
