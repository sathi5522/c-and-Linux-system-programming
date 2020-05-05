obj-m=block_driver.o

KDIR=/lib/modules/$(shell uname -r)/build

block_driver:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
install:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules_install
