# Raspberry Pi 4B CSI Driver for YUV and RAW10 Input

## Introduction

This is a kernel driver for the Raspberry Pi 4B to receive YUV data over a 2-lane CSI interface. Additionally, there is support for receiving RAW10 data.

---

## How to Install the Driver

To install the driver, clone the GitHub repository onto your Raspberry Pi. Then, navigate into the cloned directory and compile the driver files using the following commands:

```bash
# Install headers required for compiling the driver
sudo apt install raspberrypi-kernel-headers

# Compile the driver
make

# Install the driver for the current session
sudo insmod custom_yuv_fpga.ko

# Copy the driver to the appropriate system directory
sudo cp custom_yuv_fpga.ko /lib/modules/$(uname -r)/kernel/drivers/media/platform/
sudo depmod -a

# Load the driver at boot by adding it to /etc/modules
sudo vim /etc/modules
# Add the following line at the end of the file:
custom_yuv_fpga
```
# How to Install the Device Tree Overlay
To link the driver to the hardware setup via a device tree overlay, follow these steps:

```bash
# Install necessary software
sudo apt install git bc bison flex libssl-dev make
sudo apt install device-tree-compiler

# Build the overlay
dtc -@ -Hepapr -I dts -O dtb -o custom_yuv_fpga.dtbo custom_yuv_fpga-overlay.dts

# Copy the overlay to the appropriate locations
sudo cp custom_yuv_fpga.dtbo /boot/overlays/
sudo cp custom_yuv_fpga.dtbo /boot/firmware/overlays/

# Enable the overlay in the config
sudo vim /boot/firmware/config.txt
# Add the following line:
dtoverlay=custom_yuv_fpga

# Reboot to apply changes
sudo reboot

```
# Verifying the Driver Installation
After rebooting, use the following commands to verify that everything is working correctly:

``` bash
# Check kernel messages for driver logs
dmesg | grep custom

# Check if a video device is present
ls /dev/video*

# List video devices and their drivers
v4l2-ctl --list-devices

# Check the full CSI media graph
media-ctl -p
```
# How to Display a Live Video Feed
To display the live feed using ffplay, use the following command:

```bash
ffplay -f v4l2 -video_size 1920x1080 -input_format yuyv422 /dev/video0
