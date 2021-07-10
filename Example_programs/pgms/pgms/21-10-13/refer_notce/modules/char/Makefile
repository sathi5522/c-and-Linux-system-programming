obj-m :=mydev.o
KDIR=/lib/modules/$(shell uname -r)/build

TARGET:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
