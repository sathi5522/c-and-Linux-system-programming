#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#define NAME "vdev1"
#include "ioctl_header.h"
struct private {
		 unsigned int size;
		 char *kbuf;
		}info;


static char *pos_add;
static dev_t mydev;
struct file_operations fops;
struct cdev *mycdev;
struct class *veda_class;
loff_t mylseek(struct file *file, loff_t noofbyt, int pos)
{

	switch(pos){

		case 0: file->f_pos = noofbyt;
			break;

		case 1: file->f_pos += noofbyt;
			break;

		case 2: file->f_pos  = info.size;
			file->f_pos += noofbyt;

		default : return -EIO;
	}

	if(file->f_pos > info.size || file->f_pos < 0)
	return -EIO;

	return file->f_pos;
			

}



ssize_t mywrite(struct file *file, const char __user *ubuf, size_t lbuf, loff_t *offset)
{

        if(lbuf > info.size)
                return -EIO;
        pos_add = info.kbuf + *offset;

        if(*offset > info.size)
                return -EIO;

        copy_from_user(pos_add,ubuf,lbuf);

        *offset += lbuf;

        pr_info("file write\n");
        return lbuf;

}



long myioctl(struct file *file, unsigned int id, unsigned long arg)
{

	
	int *si;	
	if(_IOC_TYPE(id) != 'v')
		return -ENOTTY;

	if(_IOC_DIR(id) & _IOC_READ){
		if(!access_ok(VERIFY_WRITE,arg,_IOC_SIZE(id)))
		 return -EIO;
	}

	if(_IOC_DIR(id) & _IOC_WRITE){
		if(!access_ok(VERIFY_READ,arg,_IOC_SIZE(id)))
		return -EIO;
	}
	si = (int *)arg;
	

	switch(id){

	case FILL_ZERO:  memset(info.kbuf,0,info.size);
			 pr_info("fill zero\n");
			 break;

	case FILL_CHAR: memset(info.kbuf,arg,info.size);
			pr_info("fill char\n");
			break;

	case SET_SIZE: info.size += arg;
		       info.kbuf = krealloc(info.kbuf,info.size,GFP_KERNEL);
		       if(!info.kbuf){
			  pr_info("krealloc");
			  return -EIO;
			}	
			break;	
	case GET_SIZE: copy_to_user(si,&info.size,sizeof(info.size));
			pr_info("get_size\n");
			break;


	default :  return -1;
	}

	pr_info("mylseek\n");
 	return 0;


}


int myrelease(struct inode *node, struct file *file)
{

	pr_info("file closed\n");
	return 0;


}
int myopen(struct inode *inode, struct file *file)
{
	file->private_data = &info;
	pr_info("file opened\n");
	return 0;
}

ssize_t myread(struct file *file, char __user *ubuf, size_t lbuf, loff_t *offset)
{
		
	if(lbuf > info.size)
		return -EIO;
	pos_add = info.kbuf + *offset;
	
	if(*offset > info.size)
		return -EIO;

	copy_to_user(ubuf,pos_add,lbuf);
	
	*offset += lbuf;
	
	pr_info("file read\n");
	return lbuf;

}




int init_module(void)
{
	info.size = 100;
	info.kbuf = kmalloc(info.size,GFP_KERNEL);
	if(!info.kbuf){
		pr_info("memory allocation failed\n");
		return -1;
		}
		
	alloc_chrdev_region(&mydev,0,1,NAME);
	fops.owner    =     THIS_MODULE;
	fops.open     =     myopen;
	fops.llseek   =     mylseek;	
	fops.read     =     myread;
	fops.write    =     mywrite;
	fops.release  =     myrelease;
	fops.unlocked_ioctl = myioctl;
	
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
	kfree(info.kbuf);	
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);
	device_destroy(veda_class,mydev);
	class_destroy(veda_class);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
