obj-m := moddep.o
obj-m += modex.o

KDIR =/lib/modules/$(shell uname -r)/build

module:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
