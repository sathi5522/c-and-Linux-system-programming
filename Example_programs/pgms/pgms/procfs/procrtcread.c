#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include<linux/proc_fs.h>
#include<asm/uaccess.h>
#include"rtc.h"

static unsigned char CMD[6] = {DATE,MONTH,YEAR,HRS,MIN,SEC};
struct proc_dir_entry *readday;

/*typedef int (read_proc_t)(char *page, char **start, off_t off,
                          int count, int *eof, void *data);
*/
int myread_proc(char *page, char **start, off_t off,int count, int *eof, void *data) {

	int d,m,y;
        char *val,buf[20];
        val = (char *)data;

	READ_T(CMD[0],d);
	READ_T(CMD[1],m);
	READ_T(CMD[2],y);
	sprintf(buf,"%x:%x:%x",d,m,y);
	copy_to_user(val,&buf,sizeof(buf));

	pr_info("read\n");

	return 0;
}


int init_module(void)
{
	readday->read_proc = myread_proc;
	
	/*extern struct proc_dir_entry *proc_mkdir(const char *,struct proc_dir_entry *);*/

	proc_mkdir("rtc",readday);
	/*extern struct proc_dir_entry *create_proc_entry(const char *name, umode_t mode,
                                                struct proc_dir_entry *parent);
	*/
	create_proc_entry("rtc",0x666,readday);

        pr_info("module inserted\n");

        return 0;
}

void cleanup_module(void) {

	/*extern void remove_proc_entry(const char *name, struct proc_dir_entry *parent);*/
        
	remove_proc_entry("rtc",readday);	

	pr_info("module removed\n");
}


MODULE_LICENSE("GPL");


