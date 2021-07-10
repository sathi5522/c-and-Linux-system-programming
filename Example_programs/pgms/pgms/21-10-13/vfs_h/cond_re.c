#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/dcache.h>
#include "cond_header.h"

loff_t mylseek(struct file *file, loff_t noofbyt, int pos)
{

	switch(pos){

	case 0:	file->f_pos = noofbyt;
		break;

	case 1: file->f_pos += noofbyt;
		break;
		
	case 2: file->f_pos = MAX;
		file->f_pos += noofbyt;
		break;

	default : return -EIO;
		}

		if(file->f_pos > MAX || file->f_pos < 0)
		return -EIO;
		 
	pr_info("mylseek\n");
	return file->f_pos;

}
ssize_t myread (struct file *file, char __user *ubuf, size_t lbuf, loff_t *offset)
{
	struct private *ptr = file->private_data;
	//ptr = file->private_data;
        if(lbuf > MAX)
                return -EIO;
       
	kbuf = ptr->buf ;
        pos_add = kbuf + (*offset);
        
	if(*offset > MAX)
                return -EIO;

        copy_to_user(ubuf,pos_add,lbuf);

        *offset += lbuf;
    

	pr_info("myread\n");
	return lbuf;
}

ssize_t mywrite(struct file *file, const char __user *ubuf, size_t lbuf, loff_t *offset)
{
	struct private *ptr = file->private_data;
	//ptr = file->private_data;
	if(lbuf > MAX)
		return -EIO;
	kbuf = ptr->buf ;
	pos_add = kbuf + (*offset);
	if(*offset > MAX)
		return -EIO;

	copy_from_user(pos_add,ubuf,lbuf);
	
	*offset += lbuf;
	
	pr_info("mywrite\n");
	return lbuf;
}


int myopen(struct inode *f_inode, struct file *file)
{

	int min;
	min = iminor(f_inode);
	switch(min){
	
		  case 0:      file->private_data = &devA;
			       		break;

		  case 1:      file->private_data = &devB;
			       		break;

	       	default: 	pr_info("no device\n");
		}


	pr_info("file_opened\n");
	return 0;

}

int myrelease(struct inode *f_inode, struct file *file)
{
	pr_info("file_closed\n");
	return 0;
}


int init_module(void)
{

	int ret;
	ret = alloc_chrdev_region(&mydev,minor,NO_OF_MINOR,DRIVER_NAME); //allocate major number& minor number  dynamically
	if(ret < 0){
		pr_info("chdev_region is failed\n");
	}
	fops.owner     = THIS_MODULE;
	fops.open      = myopen;
	fops.read      = myread;
	fops.llseek    = mylseek;
	fops.write     = mywrite;
	fops.release   = myrelease;
	
	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,NO_OF_MINOR);
	
	major = MAJOR(mydev);
	
	veda_class = class_create(THIS_MODULE,"VIRTUAL");

	for( ;minor < NO_OF_MINOR;  minor++)
		device_create(veda_class,NULL,MKDEV(major,minor),NULL,"%s%d","vdev",(minor+1));	

	pr_info("module inserted\n");
	return 0;
}

void cleanup_module(void)
{
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,NO_OF_MINOR);

	for(minor = 0; minor < NO_OF_MINOR; minor++)
		device_destroy(veda_class,MKDEV(major,minor));
	
	class_destroy(veda_class);
	pr_info("module removed\n");
}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("CONDITIONAL PRINTING");
MODULE_LICENSE("GPL");
