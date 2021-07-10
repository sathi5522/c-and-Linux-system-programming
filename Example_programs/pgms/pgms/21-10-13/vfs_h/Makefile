#obj-m := rtc_dd.o
obj-m := ioctl_d.o
#obj-m := auto_reg.o
#obj-m := rd_wr.o
#obj-m := dynamic_d.o
#obj-m := autodo.o
KDIR = /lib/modules/3.5.0-23-generic/build

static_d:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean :
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
