
#define SEC       0x00
#define MIN       0x02
#define HOUR      0x04
#define DATE      0x07
#define MONTH     0x08
#define YEAR      0x09
#define CMD_REG   0x70
#define DATA_REG  0x71

#define READ_T(index,store)    outb(index,CMD_REG);\
			       store = inb(DATA_REG)

