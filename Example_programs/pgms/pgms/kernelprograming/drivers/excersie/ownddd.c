#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#define DIV_NAME "vDev"

dev_t mydev;
static struct cdev *mycdev;
static struct file_operations fops;
static struct class *veda_class;

/*int (*open) (struct inode *, struct file *);*/

static int myopen(struct inode *in, struct file *fi){
	printk("open call\n");
	return 0;
}

/*ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);*/

static ssize_t mywrite(struct file *fi, const char __user *ubuf, size_t sz, loff_t *pos) {
	int ret;
	char kbuf[25];
	ret = copy_from_user(kbuf,ubuf,sz);
	if(ret)
		return -1;
	printk("User Buffer : %s\n", kbuf);	
	pr_info("write call\n");
	return 0;	

}	


/*ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);*/

static ssize_t myread(struct file *fi, char __user *ubuf1, size_t sz, loff_t *pos) {
	char kbuff[25] = "hello world";
	copy_to_user(ubuf1,kbuff,25);
	printk("read call\n");
	return 0;
}


int init_module(void) {
	unsigned int minor = 0,count = 1;
	
	alloc_chrdev_region(&mydev,minor,count,DIV_NAME);	

	fops.owner = THIS_MODULE;
	fops.open  = myopen;
	fops.write = mywrite;
	fops.read  = myread;

	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,1);

	veda_class = class_create(THIS_MODULE,"VIRTUAL");
        device_create(veda_class,NULL,mydev,NULL,"%s%d","sat",5);

	printk("module inserted\n");
	pr_info("major number = %d,minor number = %d\n",MAJOR(mydev),MINOR(mydev));
	return 0;
}

void cleanup_module(void) {

	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);

	device_destroy(veda_class,mydev);
        class_destroy(veda_class);

	printk("module removed\n");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");
