obj-m :=map1.o
KDIR=/lib/modules/$(shell uname -r)/build
map:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

