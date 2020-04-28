/*Major and Minior number static*/
/*steps for creating char driver
        1. create a device node
                mknod /dev/my_cdev c 300 0
        2. implementthe driver operations and register with vfs layer
        3. insert the driverusing a kernel module
                insmod char_driver.ko
        4. write an application that initiates operations on our driver through common file api
*/

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define MIN_NUM 0
#define MAJOR_NUM 300
#define CHAR_DEV_NAME "my_cdev"

static dev_t mydev;
struct cdev *mycdev;
int count = 1, inuse = 0;

int myopen(struct inode *inode, struct file *file)

{

        printk("file opened\n");

        return 0;

}

ssize_t myread(struct file *file, char __user *usr, size_t val, loff_t *var)

{

        printk("file read\n");

        return 0;
}

ssize_t mywrite(struct file *file, const char __user *usr, size_t val, loff_t *var)

{

        printk("file write\n");

        return 0;

}


int myrelease(struct inode *inode, struct file *file)

{

        printk("file released\n");

        return 0;

}

/* 2. implementthe driver operations and register with vfs layer*/
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

        mydev = MKDEV(MAJOR_NUM, MIN_NUM);
        register_chrdev_region(mydev, count, CHAR_DEV_NAME);


	mycdev = cdev_alloc();
        cdev_init(mycdev, &my_fops);

        ret = cdev_add(mycdev, mydev, count);

        if(ret < 0) {
                printk("Error registering device driver\n");
                return ret;
        }
        printk("char driver module loaded\n");
        return 0;
}

static void __exit my_exit(void)
{
        cdev_del(mycdev);
        unregister_chrdev_region(mydev,1);
        printk("char driver module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("MAJOR AND MINOR NO STATIC");
MODULE_LICENSE("GPL");
