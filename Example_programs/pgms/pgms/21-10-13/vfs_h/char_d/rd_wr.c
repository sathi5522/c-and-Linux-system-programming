#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#define NAME "vdev"


static dev_t mydev;
struct file_operations fops;
struct cdev *mycdev;
struct class *veda_class;
static int baseminor=0,glob = 0;
static char kbuf[1024],*pos_add;/*Kernel Buffer */
static loff_t  seek_last;


loff_t mylseek(struct file * file, loff_t noofbyt, int pos)
{
	pr_info("lseek");

	switch(pos){

	case 0 :        file->f_pos = 0; 
			file->f_pos += noofbyt;
			break;
	
	case 1 : 	file->f_pos += noofbyt;
			break;

	case 2 :      file->f_pos = seek_last; 
		      file->f_pos +=  noofbyt;
			break;
	default :     return -EIO;
	}
	if((file->f_pos > 1024) || (file->f_pos < 0) )
	return -EIO;	
	return file->f_pos;

}







int myopen(struct inode *inode, struct file *file)
{
		
	  
        if(glob == 0){   
	glob = 1 ;                     //file synchronisation;
	pr_info("file opened\n");
	return 0;
	}
	return -EIO;
}

ssize_t myread(struct file *file, char __user *usr, size_t siz, loff_t *offset)
{

	int ret;
	if(siz > 1024)
		siz = 1024;
	pos_add = kbuf + (*offset);

	if(*offset >= 1024)
		return -1;

	ret =copy_to_user(usr,pos_add,siz);
	
	if(ret)
		return -EIO;

	pr_info("file read\n");

	*offset += siz;

	return siz;
	
	
}



ssize_t mywrite (struct file *file, const char __user *usr , size_t siz, loff_t *offset)
{

	int ret;
	if(siz > 1024)
		return -EIO;

	
	pos_add = kbuf + (*offset);

	if(*offset >= 1024)
		return -EIO;


	ret = copy_from_user(pos_add,usr,siz);
	if(ret)
		return -EIO;
	pr_info("file write: %s",kbuf);


	*offset += siz;
	seek_last = *offset;
	pr_info("offset :%d",*offset);
	return siz;


}
int myrelease(struct inode *inode,struct file *file)
{
	glob = 0;                                            //file synchronisation
	pr_info("file closed\n");

	return 0;
}

int init_module(void)
{

	alloc_chrdev_region(&mydev,baseminor,1,NAME);
	
	fops.owner = THIS_MODULE;
	fops.open = myopen;	
	fops.llseek = mylseek;
	fops.read = myread;
	fops.write = mywrite;
	fops.release = myrelease;

	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,1);

	veda_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(veda_class,NULL,mydev,NULL,"%s","vdev3");



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


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
