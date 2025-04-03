#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple dummy Raspberry Pi driver");
MODULE_VERSION("1.0");

static int __init dummy_driver_init(void) {
    printk(KERN_INFO "Hello World: Dummy Raspberry Pi Driver Installed\n");
    return 0;
}

static void __exit dummy_driver_exit(void) {
    printk(KERN_INFO "Goodbye World: Dummy Raspberry Pi Driver Removed\n");
}

module_init(dummy_driver_init);
module_exit(dummy_driver_exit);