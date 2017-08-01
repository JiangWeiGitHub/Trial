ifneq ($(KERNELRELEASE),)
	obj-m := hello.o
else
	KERNELDIR :=/lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
all:
	$(MAKE) -C $(KERNELDIR) SUBDIRS=$(PWD) modules
endif
clean:
	rm -f *.o *.ko *.mod.c .hello*