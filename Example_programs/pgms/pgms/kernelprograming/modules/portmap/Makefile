obj-m :=funrtc1.o
KDIR=/lib/modules/$(shell uname -r)/build
funrtc1:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

