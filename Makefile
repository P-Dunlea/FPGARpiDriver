KERNEL_ROOT=/lib/modules/$(shell uname -r)/build 
PWD=$(shell pwd)

obj-m := TestDriver.o custom_yuv_fpga.o custom_raw10_fpga.o

all:
	make -C $(KERNEL_ROOT) M=$(PWD) modules

clean:
	make -C $(KERNEL_ROOT) M=$(PWD) clean