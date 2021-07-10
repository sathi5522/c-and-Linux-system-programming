#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/proc_fs.h>
#include<linux/uaccess.h>
#include"rtc.h"
//char mydata[100];
static struct proc_dir_entry *myproc_file,*file2;

static int myproc_read(char *page,char **start,off_t off,int count,int *eof,void *data) {
	int len;
	char d,m,y;
	READ_T(DATE,d);
	READ_T(MONTH,m);
	READ_T(YEAR,y);
	len = sprintf(page,"%x:%x:%x",d,m,y);
	pr_info("%d\n",len);
	return len;
}
static int myproc_read1(char *page,char **start,off_t off,int count,int *eof,void *data) {
        int len;
        char h,n,s;
        READ_T(HRS,h);
        READ_T(MIN,n);
        READ_T(SEC,s);
        len = sprintf(page,"%x:%x:%x",h,n,s);
        pr_info("%d\n",len);
        return len;
}

/*static int myproc_write(struct file *file,const char *buffer, unsigned long count,void *data) {
	int len;
	if(count > 100)
		len = 100;
	else
		len = count;
	copy_from_user(mydata,buffer,len);
	return len;

}*/
int init_module(void) {
	myproc_file = create_proc_entry("mytstproc",0666,NULL);
	if(myproc_file == NULL)
		return -EIO;

	myproc_file->data = 0;
	myproc_file->read_proc  = myproc_read;
	//myproc_file->write_proc = myproc_write;
	
	file2 = create_proc_entry("mytstproc1",0666,NULL);
	if(myproc_file == NULL)
		return -EIO;

	file2->data = 0;
	file2->read_proc  = myproc_read1;
	//file2->write_proc = myproc_write;
	pr_info("module inserted\n");
	return 0;
}

void cleanup_module(void) {
	
	remove_proc_entry("mytstproc",NULL);
	remove_proc_entry("mytstproc1",NULL);

	pr_info("module removed\n");
}

MODULE_LICENSE("GPL");

