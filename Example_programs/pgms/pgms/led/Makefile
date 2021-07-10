obj-m :=led2.o
KDIR=/home/morning/sathi/embedded/rootfs/rootfs/lib/modules/2.6.37.2/build
lab:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean


