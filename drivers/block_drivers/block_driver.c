#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/errno.h>
#include<linux/types.h>
#include<linux/vmalloc.h>
#include<linux/genhd.h>
#include<linux/blkdev.h>
#include<linux/hdreg.h>
#include<linux/device.h>
#include<asm/uaccess.h>
#include<linux/blkpg.h>
#include<linux/version.h>

static int major_num = 0;
module_param(major_num, int, 0);

static int hardsect_size = 512;
module_param(hardsect_size, int, 0);

static int nsectors = 16024; /*how big the driveis*/
module_param(nsectors, int, 0);

static struct class *v_class = NULL;

static struct sbd_device {
	unsigned long size;	//size ofthe device
	spinlock_t lock;
	u8 *data;		//array to store disk data
	struct gendisk *gd;	//kernel representation of device
}Device;

dev_t mydev;

#define KERNEL_SECTOR_SIZE 512
static void sbd_request(struct request_queue *q);

static struct request_queue *Queue;

static int sbd_open(struct block_device *bd, fmode_t pos)
{
	return 0;
}

/* the device operations structure */
static struct block_device_operations sbd_ops = {
		.owner = THIS_MODULE,
		.open = sbd_open,
};

void do_actual_req(struct request *req)
{
	int max_sectors, dir, size, i;
	char *addr;
	int error;
	struct bio *bio;
	struct bio_vec *bv;	/* points to each segment in the bio */
	char *buffer;
	int sector = blk_rq_pos(req);	/* starting sector */
	max_sectors = blk_rq_sectors(req);	/* total num of sectors to process */

	/* this should not cross our device limit */
	if (sector > nsectors || (sector + max_sectors)> nsectors) {
		__blk_end_request(req, 0, 0);
		return;
	}

	/* request direction */
	dir = rq_data_dir(req);
	addr = Device.data + (sector << 9);

	__rq_for_each_bio(bio,req) {	/* get each bio from request */
		bio_for_each_segment(bv, bio, i) {
			/* get each bio from request */
			size = bv->bv_len;	//size of current segment
			buffer = page_address(bv->bv_page) + bv->bv_offset;
			if(dir == WRITE) {
				printk("WRITINGTO DISK\n");
				memcpy(addr, buffer, size);
			} else {
				printk("READING FROM DISK\n");
				memcpy(buffer, addr, size);
			}
			addr += size;
		}
	}
	error= req->errors ? -EIO : 0;
	__blk_end_request(req, error, req->__data_len << 9);
}

static void sbd_request(struct request_queue *q)
{
	struct request *req;
	
	/* take requests one by one from the request queue and process it */
	while((req = blk_fetch_request(q)) != NULL) {
		//if(!blk_fs_request(req)) {
		if (req == NULL || (req->cmd_type != REQ_TYPE_FS)) {
			__blk_end_request(req, 0, 0);	//if not end this request
			continue;
		}
		/* process the request */
		do_actual_req(req);
	}
}

static int __init sbd_init(void)
{
	struct device *dev = NULL;
	
	/* set up our device information */
	
	/* setp 1: allocate memory for ramdisk */
	Device.size = nsectors * hardsect_size;
	spin_lock_init(&Device.lock);
	Device.data = vmalloc(Device.size);

	if (Device.data == NULL)
		return -ENOMEM;
	memset(Device.data, 0, Device.size);

	/* step 2: Register with Generic Block layer 
	   a) create a request queue and assign req routine as callback */
	Queue = blk_init_queue(sbd_request, &Device.lock);
	if (Queue == NULL)
		goto out;
	/* b) assign sector size to req queue */
	blk_queue_logical_block_size(Queue, hardsect_size);

	/* setp 3: register with VFS 
	   a) accquire/reserve major and minor no on block device list
	*/
	major_num = register_blkdev(major_num, "sbd0");
	if (major_num <= 0) {
		printk(KERN_WARNING "sbd : unable to get major number\n");
		goto out;
	}
	printk("Success for major number\n");
	mydev = MKDEV(major_num, 0);

	/* b) register with device tree for udev services */
	v_class = class_create(THIS_MODULE, "sathi");
	if (IS_ERR(v_class)) {
		printk(KERN_ERR "Error registering class\n");
	}
	dev = device_create(v_class, NULL, mydev, NULL, "sbd0");

	/* c) allocate a new instance of struct gendisk, fill it with driver details, and register with vfs */
	Device.gd = alloc_disk(1);
	if (!Device.gd) 
		goto out_unregister;
	Device.gd->major = major_num;
	Device.gd->first_minor = 0;
	Device.gd->fops = &sbd_ops;
	Device.gd->private_data = &Device;
	strcpy(Device.gd->disk_name, "sbd0");

	set_capacity(Device.gd, nsectors * (hardsect_size / KERNEL_SECTOR_SIZE));
	Device.gd->queue = Queue;

	add_disk(Device.gd);
	return 0;
out_unregister:
	printk("\n at unregister");
	unregister_blkdev(major_num, "sbd0");
out:
	vfree(Device.data);
	return -ENOMEM;
}

static void __exit sbd_exit(void)
{
	del_gendisk(Device.gd);
	put_disk(Device.gd);
	
	device_destroy(v_class,mydev);
	class_destroy(v_class);
	unregister_blkdev(major_num, "sbd0");
	blk_cleanup_queue(Queue);
	vfree(Device.data);
	printk("\n Module Removed\n");
}

module_init(sbd_init);
module_exit(sbd_exit);
MODULE_LICENSE("Dual BSD/GPL");
