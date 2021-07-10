#define DRIVER_NAME  "vdev"
#define NO_OF_MINOR   2
#define MAX           100


static loff_t seek_last;
static char kbufA[MAX],kbufB[MAX],*pos_add,*kbuf;
static dev_t mydev;
static struct cdev *mycdev;
static struct file_operations fops;
static struct class *veda_class;
static int minor = 0,major;
static struct private{
                        unsigned int minor;
                        char *buf;
                     };

struct private devA = { .minor = 0,
                     .buf = kbufA };

struct private devB = { .minor = 1,
                     .buf = kbufB};


