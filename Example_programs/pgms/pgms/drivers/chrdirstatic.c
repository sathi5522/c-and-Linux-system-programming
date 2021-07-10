#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#define MAJ 300
#define MIN 0
#define DIV_NAME "vdevvv"

dev_t mydev;
struct cdev *mycdev;
struct file_operations fops;

/*int (*open) (struct inode *, struct file *);*/

int myopen(struct inode *in, struct file *fi){
	printk("open call\n");
	return 0;
}
/*ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);*/

ssize_t myread (struct file *fi, char __user *buf, size_t sz, loff_t *pos) {
	printk("read call\n");
	return 0;
}


int init_module(void) {

	mydev = MKDEV(MAJ,MIN);
	register_chrdev_region(mydev,1,DIV_NAME);

	fops.owner = THIS_MODULE;
	fops.open  = myopen;
	fops.read  = myread;

	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,1);
	printk("module inserted\n");
	return 0;
}

void cleanup_module(void) {

	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);
	printk("module removed\n");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");
