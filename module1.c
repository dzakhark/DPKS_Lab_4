
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static unsigned int repeats = 1;
module_param(repeats, uint, S_IRUGO);
MODULE_PARM_DESC(repeats, "How many times to print hello");

static int __init module1_init(void)
{
	unsigned int repeat;

	if (repeats > 10)
	{
		printk(KERN_ERR "Cannot repeat more than 10 times\n");
		return -EINVAL;
	}

	if (repeats >= 5 && repeats <= 10)
	{
		printk(KERN_WARNING "Repeatition from 5 to 10 times\n");
	}

	if (repeats == 0)
	{
		printk(KERN_WARNING "No repeatition\n");
	}

	for (repeat = 0; repeat < repeats; repeat++)
	{
		printk(KERN_INFO "Hello there!\n");
	}

	return 0;
}

static void __exit module1_exit(void)
{
	printk(KERN_EMERG "Module 1 exit\n");
}

module_init(module1_init);
module_exit(module1_exit);

MODULE_AUTHOR("Dmytro Zakharchuk");
MODULE_DESCRIPTION("Test build linux module");
MODULE_LICENSE("Dual BSD/GPL");
