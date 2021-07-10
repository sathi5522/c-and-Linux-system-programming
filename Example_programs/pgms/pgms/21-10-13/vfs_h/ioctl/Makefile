
obj-m := ioctl.o

KDIR = /lib/modules/$(shell uname -r)/build

static_d:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean :
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
