obj-m :=ex1.o
KDIR=/lib/modules/3.2.0-39-generic-pae/build
EX1:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
