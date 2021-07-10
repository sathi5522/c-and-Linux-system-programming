obj-m :=a2ksmnum.o
KDIR=/lib/modules/$(shell uname -r)/build
lab:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

