obj-m :=redir.o
KDIR=/lib/modules/$(shell uname -r)/build

APP:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

