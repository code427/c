#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello world \n");

	return 0;
}

void static  __exit hello_cleanup(void)
{
	printk(KERN_INFO "bye \n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_LICENSE("GPL");
