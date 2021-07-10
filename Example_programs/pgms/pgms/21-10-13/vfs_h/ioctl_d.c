#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#define NAME "vdev1"
#include "ioctl_header.h"
#define SIZE 100

static dev_t mydev;
static struct file_operations fops;
static cdev *mycdev;
static char *pos_add,*buf;
static struct class *veda_class;
static struct private  {
			
			unsigned int size;
			char *kbuf;

			}obj;

obj.size = 100;



loff_t mylseek(struct file *file, loff_t noofbyt, int pos)
{


        switch(pos){

        case 0: file->f_pos = noofbyt;
                break;

        case 1: file->f_pos += noofbyt;
                break;

        case 2: file->f_pos = obj.size;
                file->f_pos += noofbyt;
                break;

        default : return -EIO;
                }

                if(file->f_pos > obj.size || file->f_pos < 0)
                return -EIO;

	pr_info("mylseek\n");
	return file->f_pos;


}

int myopen(struct inode *inode, struct file *file)
{
	
	file->private_data = &obj;
	pr_info("file opened\n");
	return 0;
}

ssize_t myread(struct file *file, char __user *usr, size_t lbuf, loff_t *offset)
{
 struct private *ptr = file->private_data;
        
        if(lbuf > obj.size)
                return -EIO;

        buf = ptr->kbuf ;
        pos_add = buf + (*offset);

        if(*offset > MAX)
                return -EIO;

        copy_to_user(ubuf,pos_add,lbuf);

        *offset += lbuf;


	pr_info("file read\n");
	return lbuf;

}
long myioctl(struct file *file, unsigned int cmd, unsigned long var)
{

	struct private *ptr = file->private_data;

	int *p;
	switch(cmd){

		case FILL_SET : memset(obj.kbuf, var, obj.size);
				pr_info("fill set\n");
				break;

		case GET_SIZE : p = sizeof(obj.size);
				pr_info("get size\n");
				break;

		case SET_SIZE : obj.buf = krealloc(obj.kbuf,var,GFP_KERNEL);
				pr_info("set size\n");
				break;

		case FILL_ZERO: memset(obj.kbuf,0,obj.size);
				pr_info("fillzero \n");
				break;

		default : return -1;
		}


		pr_info("myioctl\n");

		return 0;

}

int myrelease (struct inode *node, struct file *file)
{

	pr_info("file closed\n");
	return 0;

}
ssize_t mywrite(struct file *file, const char __user *usr, size_t lbuf, loff_t *offset)
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




	pr_info("file write\n");
	return lbuf;

}


int init_module(void)
{
//	mydev = MKDEV(MAX,MIN);
//	register_chrdev_region(mydev,1,NAME);
	
	obj.kbuf = kmalloc(obj.size,GFP_KERNEL);
	if(!obj.kbuf){

		return -1;
	};

	alloc_chrdev_region(&mydev,0,1,NAME);
	fops.owner          =   THIS_MODULE;
	fops.open           =   myopen;	
	fops.read           =   myread;
	fops.write          =   mywrite;
	fops.release        =   myrelease;
	fops.llseek         =   mylseek;
	fops.unlocked_ioctl =   myioctl;
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
	
	kfree(obj.kbuf);
	cdev_del(mycdev);
	unregister_chrdev_region(mydev,1);
	device_destroy(veda_class,mydev);
	class_destroy(veda_class);
	pr_info("module removed\n");
	

}


MODULE_AUTHOR("NAGESH");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
