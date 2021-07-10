#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x35ec255d, "module_layout" },
	{ 0x999872e2, "remove_proc_entry" },
	{ 0x50eedeb8, "printk" },
	{ 0xfc635aa2, "create_proc_entry" },
	{ 0x2febb866, "proc_mkdir" },
	{ 0xc5c74531, "__mutex_init" },
	{ 0x91715312, "sprintf" },
	{ 0x6339a8bc, "mutex_unlock" },
	{ 0xb6be82cd, "pv_cpu_ops" },
	{ 0xcf510c4a, "mutex_lock" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "0E443674B4CB418D74EBEE6");
