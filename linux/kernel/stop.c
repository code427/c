#include<linux/kernel.h>
#include<linux/module.h>

void cleanup_module()
{
	printk(KERN_INFO “this is part 2\n";
}
