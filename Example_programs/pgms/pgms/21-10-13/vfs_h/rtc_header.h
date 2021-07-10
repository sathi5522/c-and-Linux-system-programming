#define SEC         0x00
#define MIN         0X02
#define HRS         0x04
#define DAY         0x06
#define DATE        0x07
#define YEAR        0x09
#define MONTH       0X08
#define ADD_REG     0x70
#define DATA_REG    0x71
#define STATUS_REG  0x71




#define READ_T(a,b)  outb(a,ADD_REG);\
		   b = inb(DATA_REG);
		
