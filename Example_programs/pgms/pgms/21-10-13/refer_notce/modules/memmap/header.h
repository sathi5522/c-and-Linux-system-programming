#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>

#define PHYADDR 0xfec00000
#define SIZE    1024

#define REMAP(ptr)  ptr = ioremap_nocache(PHYADDR,SIZE);
