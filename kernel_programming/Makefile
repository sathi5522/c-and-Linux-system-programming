obj-m=example_module.o
obj-m+=export_symbol.o
obj-m+=module_param.o
obj-m+=interrupt.o

KDIR=/lib/modules/$(shell uname -r)/build

example_module:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
install:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules_install
#make modules_install will copy all the ko files into /lib/modules/kernelstampdirectory.
