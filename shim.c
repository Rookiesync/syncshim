#include <linux/init.h>
#include <linux/module.h>//
#include <net/tcp.h>//
#include <linux/netfilter.h>
#include <linux/init.h>
#include <linux/netfilter_ipv4.h>
#include <linux/kernel.h>
#include <linux/ip.h>
#include <linux/if_ether.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/if_packet.h>
#include <linux/syscalls.h>
#include <asm/unistd.h>
#include <asm/uaccess.h>


int init_modules(struct nf_hook_ops * nfh)
{
	nf_register_hook(nfh);
	return 0;
}
EXPORT_SYMBOL(init_modules);


void clean_modules(struct nf_hook_ops * nfh)
{
	nf_unregister_hook(nfh);
}
EXPORT_SYMBOL(clean_modules);

int tcp_register_cc_fit(struct tcp_congestion_ops *ca)
{
	printk(ca->name);	
	return tcp_register_congestion_control(ca);
}
EXPORT_SYMBOL(tcp_register_cc_fit);

void tcp_unregister_cc_fit(struct tcp_congestion_ops *ca)
{	
	printk(ca->name);
	tcp_unregister_congestion_control(ca);
}
EXPORT_SYMBOL(tcp_unregister_cc_fit);

MODULE_AUTHOR("TCP Engines");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TCP SHIM");
