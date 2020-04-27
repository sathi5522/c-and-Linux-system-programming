obj-m=example_module.o
obj-m+=export_symbol.o
obj-m+=module_param.o

KDIR=/lib/modules/$(shell uname -r)/build

example_module:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
