obj-m=memorymap_chrdrv.o

KDIR=/lib/modules/$(shell uname -r)/build

example_module:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
install:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules_install
