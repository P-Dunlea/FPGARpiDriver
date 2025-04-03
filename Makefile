KERNEL_ROOT=/lib/modules/$(shell uname -r)/build 
PWD=$(shell pwd)

obj-m := TestDriver.o

all:
	make -C $(KERNEL_ROOT) M=$(PWD) modules

clean:
	make -C $(KERNEL_ROOT) M=$(PWD) clean