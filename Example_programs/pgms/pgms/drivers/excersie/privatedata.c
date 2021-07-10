#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include"header.h"

dev_t mydev;
static struct cdev *mycdev;
static struct file_operations fops;
char DEVBUFA[MAX],DEVBUFB[MAX];
char *pos_addr;
int seek_last;
static int myopen(struct inode *in, struct file *fi){
        printk("open call\n");
        return 0;
}

static ssize_t myread(struct file *file, char __user *ubuf, size_t count, loff_t *offset)
{
        int ret,minior;
	minior = MINOR(file->f_path.dentry->d_inode->i_rdev);
	switch(minior) {
		case 0:
        		pos_addr = DEVBUFA + *offset;
        		if(count>MAX)
                		count = MAX;
       	 		ret = copy_to_user(ubuf,pos_addr,count);
        		if(ret)
                		return -EIO;
			*offset+=count;
			break;
		case 1:
                        pos_addr = DEVBUFB + *offset;
                        if(count>MAX)
                                count = MAX;
                        ret = copy_to_user(ubuf,pos_addr,count);
                        if(ret)
                                return -EIO;
                        *offset+=count;
                        break;
		default:
			return -EIO;
	}



        pr_info("file read\n");

        return count;

}


static ssize_t mywrite (struct file *file, const char __user *ubuf , size_t lbuf, loff_t *offset)
{
        int ret,minior;
	minior = MINOR(file->f_path.dentry->d_inode->i_rdev);
	switch(minior) {
		case 0:
        		if((*offset)>=MAX)
                	return -EIO;

       			pos_addr = DEVBUFA + *offset;

        		if(lbuf>MAX)
                	return -EIO;
        		ret = copy_from_user(pos_addr,ubuf,lbuf);

        		if(ret)
                		return -EIO;
        		*offset+=lbuf;
			seek_last = *offset;
	
        		pr_info("file write\n");
       	 		return lbuf;
			break;
		case 1:
                        if((*offset)>=MAX)
                        return -EIO;

                        pos_addr = DEVBUFB + *offset;

                        if(lbuf>MAX)
                        return -EIO;
                        ret = copy_from_user(pos_addr,ubuf,lbuf);

                        if(ret)
                                return -EIO;
                        *offset+=lbuf;
			seek_last = *offset;
        		pr_info("file write\n");
	  		return lbuf;
			break;
		default:
			return -EIO;
			break;
	}
        




	


}
static int myrelease(struct inode *inode,struct file *file)
{



        pr_info("file closed\n");

        return 0;
}

loff_t mylseek(struct file * file, loff_t noofbyt, int pos)
{
        pr_info("lseek");
	loff_t tempos;

	tempos = file->f_pos;
        
	switch(pos){

        	case 0 :        
			tempos =0;
                        tempos += noofbyt;
                        break;

        	case 1 :        
			tempos += noofbyt;
                        break;

        	case 2 :      
			tempos = seek_last;
                        tempos -=  noofbyt;
                        break;
        	default :     
			return -EIO;
        }
        if((tempos > MAX) || (tempos < MIN) )
        	return -EIO;
        return tempos;

}



int init_module(void) {
        unsigned int minor = 0,count = 2;

        alloc_chrdev_region(&mydev,minor,count,DIV_NAME);

        fops.owner = THIS_MODULE;
        fops.open  = myopen;
        fops.read  = myread;
	fops.write = mywrite;
	fops.release = myrelease;
	fops.llseek = mylseek;

        mycdev = cdev_alloc();
        cdev_init(mycdev,&fops);
        cdev_add(mycdev,mydev,2);
        printk("module inserted\n");
	return 0;
}

void cleanup_module(void) {

        cdev_del(mycdev);
        unregister_chrdev_region(mydev,2);
        printk("module removed\n");
}

MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("first module");
MODULE_LICENSE("GPL");

