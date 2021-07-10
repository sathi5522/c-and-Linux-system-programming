#define SEC 		0x00
#define MIN 		0x02
#define HRS 		0x04
#define DATE 		0x07
#define MONTH 		0x08
#define YEAR 		0x09
#define COMMAND_REG 	0x70
#define DATA_REG 	0x71
#define STATUS_REG 	0x71

#define READ_T(a,b)  outb_p(a,COMMAND_REG);\
		   b = inb_p(STATUS_REG);
