/*example for copy_from_user and copy_to_user*/
/*steps for creating char driver
        1. implementthe driver operations and register with vfs layer
	2. create class and device
        3. insert the driverusing a kernel module
                insmod char_drv_dynamic.ko
        4. write an application that initiates operations on our driver through common file api
*/

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/uaccess.h>

#define CHAR_DEV_NAME "my_cdev"

static dev_t mydev;
struct cdev *mycdev;
struct class *my_class;

int myopen(struct inode *inode, struct file *file)
{
        printk("file opened\n");

        return 0;
}

ssize_t myread(struct file *file, char __user *usr, size_t val, loff_t *var)
{
	char kbuff[25] = "Hello world";
	copy_to_user(usr, kbuff, 25);
        printk("file read\n");

        return 0;
}

ssize_t mywrite(struct file *file, const char __user *usr, size_t val, loff_t *var)
{
	int r;
	char kbuf[25];
	
	r = copy_from_user(kbuf, usr, val);

	if(r)
		return -1;
	printk("user Buffer %s\n",kbuf);
        printk("file write\n");

        return 0;
}


int myrelease(struct inode *inode, struct file *file)
{
        printk("file released\n");

        return 0;
}

/* 1. implementthe driver operations and register with vfs layer*/
struct file_operations my_fops = {
        .owner=THIS_MODULE,
        .open=myopen,
        .write=mywrite,
        .read=myread,
        .release=myrelease
};

static int __init my_init(void)
{
        int ret;
	unsigned int minior = 0, count = 1;

        if(alloc_chrdev_region(&mydev, minior, count, CHAR_DEV_NAME) < 0) {
		printk(KERN_ERR"failed to reserve major/minior range\n");
		return -1;
	} 


	mycdev = cdev_alloc();
	if(mycdev == NULL) {
		printk(KERN_ERR"cdv_alloc failed\n");
		unregister_chrdev_region(mydev, count);
		return -1;
	}
        cdev_init(mycdev, &my_fops);

        ret = cdev_add(mycdev, mydev, count);

        if(ret < 0) {
                printk("Error registering device driver\n");
		cdev_del(mycdev);
		unregister_chrdev_region(mydev, count);
                return ret;
        }
	/* 2. create class and device*/
	my_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(my_class, NULL, mydev, NULL, "%s%d","my_cdev",1);
        printk("char driver module loaded Major no : %d Minior no : %d\n", MAJOR(mydev), MINOR(mydev));
        return 0;
}

static void __exit my_exit(void)
{
	device_destroy(my_class,mydev);
	class_destroy(my_class);
        cdev_del(mycdev);
        unregister_chrdev_region(mydev,1);
        printk("char driver module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("MAJOR AND MINOR NUM DYNAMIC");
MODULE_LICENSE("GPL");
