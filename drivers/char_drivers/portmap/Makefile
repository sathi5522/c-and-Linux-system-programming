obj-m:=chrrtc.o

KDIR=/lib/modules/$(shell uname -r)/build

rtc:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
