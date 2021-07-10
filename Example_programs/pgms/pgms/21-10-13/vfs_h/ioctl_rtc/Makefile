obj-m :=char_rtc.o

KDIR = /lib/modules/$(shell uname -r)/build

out: 
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
	
