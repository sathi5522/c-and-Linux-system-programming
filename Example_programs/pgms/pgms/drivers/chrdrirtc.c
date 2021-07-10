#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include "rtc.h"
#define NAME "vdev1"

static unsigned char CMD[6] = {DATE,MONTH,YEAR,HRS,MIN,SEC};
static int msg;
static dev_t mydev;
struct file_operations fops;
struct cdev *mycdev;
struct class *veda_class;
char kbuf[30];
int myopen(struct inode *inode, struct file *file)
{

	pr_info("file opened\n");
	return 0;
}

ssize_t myread(struct file *file, char __user *usr, size_t val, loff_t *var)
{
	int buf,d,m,y,h,n,s;
	buf = CMD[*var];
	//pr_info("%d\n",*var);	
	if(*var < 6) {
		READ_T(buf,msg);
		copy_to_user(usr,&msg,val);
		pr_info("file read\n");
	}
	else if(*var == 6) {
		READ_T(CMD[0],d);
		READ_T(CMD[1],m);
		READ_T(CMD[2],y);
		READ_T(CMD[3],h);
		READ_T(CMD[4],n);
		READ_T(CMD[5],s);
		sprintf(kbuf,"%x:%x:%x:%x:%x:%x",d,m,y,h,n,s);
		pr_info("%s\n",kbuf);
		copy_to_user(usr,&kbuf,val);
		pr_info("%d\n",val);
	}
	else {
		return -EIO;
	}

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
                case 2: offset = offset - length;
                        break;
                default: pr_info("error with offset\n");
                        break;
        }
        if(offset < 0 || offset > 6)
                return EIO;

        fip->f_pos = offset;

        return offset;
}




ssize_t mywrite (struct file *file, const char __user *usr , size_t val, loff_t *var)
{
	int buf;
	buf = CMD[*var];
        //pr_info("%d\n",*var);
        if(*var < 6) {

                copy_from_user(&msg,usr,val);
		pr_info("%x\n",msg);
                WRITE_T(buf,msg);
                pr_info("file write\n");
        }

	/*copy_from_user(&index,usr,val);

	READ_T(command[index],msg);
	if(index == 7){

	READ_T(command[0],sec);
	READ_T(command[1],min);
	READ_T(command[2],hour);
	READ_T(command[4],date);
	READ_T(command[5],month);
	READ_T(command[6],year);
	
	}*/
	
	return 0;


}
int myrelease(struct inode *inode,struct file *file)
{



	pr_info("file closed\n");

	return 0;
}

int init_module(void)
{
	alloc_chrdev_region(&mydev,0,1,NAME);
	
	fops.owner = THIS_MODULE;
	fops.open = myopen;	
	fops.read = myread;
	fops.write = mywrite;
	fops.release = myrelease;
	fops.llseek = mylseek;

	mycdev = cdev_alloc();
	cdev_init(mycdev,&fops);
	cdev_add(mycdev,mydev,1);

	veda_class = class_create(THIS_MODULE,"VIRTUAL");
	device_create(veda_class,NULL,mydev,NULL,"%s%d","sat",4);



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


MODULE_AUTHOR("sathi");
MODULE_DESCRIPTION("STATIC");
MODULE_LICENSE("GPL");
