#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/uaccess.h>
#define DIV_NAME "vdev1"
static dev_t mydev;
static struct file_operations fops;
static struct cdev *mycdev;
static struct class *veda_class;
char kbuf[1024];/*kernel buffer*/
char *pos_addr;
int see_end;
static int myopen(struct inode *inode, struct file *file) {
        pr_info("file opened\n");
        return 0;
	
}
/*loff_t (*llseek) (struct file *, loff_t, int);*/
static loff_t mylseek (struct file *file, loff_t off, int pos){
	if(off <= 1024) {
		switch(pos) {
			case 0:
				file->f_pos = 0;
				file->f_pos += off;
				break;
			case 1:
				file->f_pos += off;
				break;

			case 2:
				file->f_pos = see_end;
				file->f_pos -= off;
				break;
			default:
				return -EIO;
				break;
		
		}
	}
	else {
		return -EIO;
	}
	return file->f_pos;
			
}
static ssize_t myread(struct file *file, char __user *ubuf, size_t count, loff_t *offset)
{
	int ret;
	pos_addr = kbuf + *offset;
	if(count>1024)
                count = 1024;
	ret = copy_to_user(ubuf,pos_addr,count);
	if(ret)
                return -EIO;


        pr_info("file read\n");
	*offset+=count;
        return 0;

}
static ssize_t mywrite (struct file *file, const char __user *ubuf , size_t lbuf, loff_t *offset)
{
	int ret;


	if((*offset)>=1024)
		return -EOF;

	pos_addr = kbuf + *offset;

	if(lbuf>1024)
		return -EIO;
	ret = copy_from_user(pos_addr,ubuf,lbuf);

	if(ret)
		return -EIO;
	*offset+=lbuf;
	see_end = *offset;


        pr_info("file write\n");
	return lbuf;



}
static int myrelease(struct inode *inode,struct file *file)
{



        pr_info("file closed\n");

        return 0;
}


int init_module(void)
{
        alloc_chrdev_region(&mydev,0,1,DIV_NAME);

        fops.owner = THIS_MODULE;
        fops.open = myopen;
        fops.read = myread;
        fops.write = mywrite;
	fops.llseek = mylseek;
        fops.release = myrelease;

        mycdev = cdev_alloc();
        cdev_init(mycdev,&fops);
        cdev_add(mycdev,mydev,1);

        veda_class = class_create(THIS_MODULE,"VIRTUAL");
        device_create(veda_class,NULL,mydev,NULL,"%s%d","sat",5);



        pr_info("module inserted\n");
        return 0;
}




void cleanup_module(void)
{
        cdev_del(mycdev);
        unregister_chrdev_region(mydev,1);
        device_destroy(veda_class,mydev);
        class_destroy(veda_class);
        pr_info("module removed\n");


}
MODULE_LICENSE("GPL");
