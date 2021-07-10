#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/proc_fs.h>
#include<linux/uaccess.h>
#include<linux/mutex.h>
#include"rtc.h"
static struct proc_dir_entry *myproc_file,*file2,*proc;
struct mutex lock;

static int myproc_read(char *page,char **start,off_t off,int count,int *eof,void *data) {

	char d,m,y;
	mutex_lock(&lock);
	READ_T(DATE,d);
	READ_T(MONTH,m);
	READ_T(YEAR,y);
	mutex_unlock(&lock);
	return sprintf(page,"Date = %x:%x:%x\n",d,m,y);
}
static int myproc_read1(char *page,char **start,off_t off,int count,int *eof,void *data) {
        
        char h,n,s;
	mutex_lock(&lock);
        READ_T(HRS,h);
        READ_T(MIN,n);
        READ_T(SEC,s);
	mutex_unlock(&lock);
        return sprintf(page,"Time = %x:%x:%x\n",h,n,s);
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
	mutex_init(&lock);
	proc = proc_mkdir("sathi",NULL);
	myproc_file = create_proc_entry("mytstproc",0666,proc);
	if(myproc_file == NULL)
		return -EIO;

	myproc_file->read_proc  = myproc_read;
	
	file2 = create_proc_entry("mytstproc1",0666,proc);
	if(myproc_file == NULL)
		return -EIO;

	file2->read_proc  = myproc_read1;
	pr_info("module inserted\n");
	return 0;
}

void cleanup_module(void) {
	
	remove_proc_entry("mytstproc",proc);
	remove_proc_entry("mytstproc1",proc);
	remove_proc_entry("sathi",NULL);
	pr_info("module removed\n");
}

MODULE_LICENSE("GPL");

