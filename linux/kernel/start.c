#include<linux/kernel.h>
#include<linux/module.h>

int init_module(void)
{
	printk(KERN_INFO "this is part 1\n");
	return 0;

}
