obj-m :=sum.o
obj-m +=mod.o
KDIR=/lib/modules/$(shell uname -r)/build
sum:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

