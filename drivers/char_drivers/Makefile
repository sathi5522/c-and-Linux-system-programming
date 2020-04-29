obj-m=char_drv.o
obj-m+=char_drv_dynamic.o
obj-m+=char_drv_udev.o
obj-m+=register_chrdev.o
obj-m+=char_write_read.o
obj-m+=misc_chrdev.o

KDIR=/lib/modules/$(shell uname -r)/build

example_module:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
install:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules_install
