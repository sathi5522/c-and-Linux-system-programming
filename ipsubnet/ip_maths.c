#include<stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <arpa/inet.h>
#include <math.h>

#define PREFIX_LEN 15      /* Max IPv4 len in A.B.C.D format */
#define MAX_MASK_LEN 32    /* MASK Maximum value */
#define COMPLEMENT(num) (num = num ^ 0xFFFFFFFF)
#define SET_BIT(val, pos) (val = val | (1 << pos))

unsigned int get_network_mask(char mask)
{
	unsigned int network_mask = 0x00000000;
	unsigned char pos = 31;
	while (mask) {
		SET_BIT(network_mask, pos);
		--mask, --pos;
	}
	return network_mask;
}

void get_abcd_ip_format(unsigned int ip_addr, char *output_buffer)
{
	sprintf(output_buffer, "%d.%d.%d.%d",
		((ip_addr & 0xFF000000) >> 24),
		((ip_addr & 0xFF0000) >> 16),
		((ip_addr & 0xFF00) >> 8),
		(ip_addr & 0xFF));
}
unsigned int get_ip_integer_equivalent(char *address)
{
	unsigned char ipbytes[4];

	sscanf(address, "%hhu.%hhu.%hhu.%hhu", ipbytes + 3,
	       ipbytes + 2,
	       ipbytes + 1,
	       ipbytes);

	return ipbytes[0] | ipbytes[1] << 8 | ipbytes[2] << 16 | ipbytes[3] << 24;
}

void get_network_id(char *ip_addr, char mask, char *output_buffer)
{
	unsigned int network_mask = get_network_mask(mask);
	unsigned int network_ip = get_ip_integer_equivalent(ip_addr);
	unsigned int network_id = network_ip & network_mask;

	get_abcd_ip_format(network_id, output_buffer);
}

void get_broadcast_address(char *ip_addr, char mask, char *output_buffer)
{
	unsigned int network_mask = get_network_mask(mask);
	unsigned int network_ip = get_ip_integer_equivalent(ip_addr);
	unsigned int network_id = network_ip & network_mask;
	unsigned int broadcast_addr = network_id | COMPLEMENT(network_mask);

	get_abcd_ip_format(broadcast_addr, output_buffer);
}

unsigned int get_subnet_cardinality(char mask)
{
	return (pow(2, MAX_MASK_LEN - mask) - 2);
}

int check_ip_subnet_membership(char *network_id, char mask, char *check_ip)
{
	unsigned int nw_ip = get_ip_integer_equivalent(network_id);
	unsigned int ip = get_ip_integer_equivalent(check_ip);
	unsigned network_mask = get_network_mask(mask);
	unsigned int chk_ip_network = ip & network_mask;

	if (chk_ip_network == nw_ip)
		return 0;
	else
		return -1;
}

int main()
{
	char ipadd_buffer[PREFIX_LEN];
	memset(ipadd_buffer, 0, PREFIX_LEN);

	char *ipaddr= "192.168.2.10";
	char mask=20;
	get_broadcast_address(ipaddr, mask, ipadd_buffer);
	printf("Broadcast address = %s\n",ipadd_buffer);

	unsigned int ip_int = get_ip_integer_equivalent(ipaddr);
	printf("the ip = %s ip_int %u\n", ipaddr, ip_int);

	ip_int = 2058138155;
	get_abcd_ip_format(ip_int,ipadd_buffer);
	printf("The ip A.B.C.D format %s\n", ipadd_buffer);

	get_network_id(ipaddr, mask, ipadd_buffer);
	printf("the networ id %s\n", ipadd_buffer);

	ip_int= get_subnet_cardinality(mask);
	printf("the allowed ips %u\n", ip_int);

	char *network_id = "192.168.0.0";
	int result = check_ip_subnet_membership(network_id, mask, ipaddr);
	if(result == 0)
		printf("ipaddr = %s is a member of subnet %s %u\n",ipaddr, network_id, mask);
	else
		printf("ipaddr = %s is not a member of subnet %s %u\n",ipaddr, network_id, mask);
	return 0;
}
