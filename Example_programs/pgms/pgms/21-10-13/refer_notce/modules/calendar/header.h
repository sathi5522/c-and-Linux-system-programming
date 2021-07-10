#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/module.h>

#define SEC 	0x00
#define MIN 	0x02
#define HOUR	0x04
#define DAYNO 	0x06
#define DATE	0x07
#define MONTH 	0x08
#define YEAR 	0x09

#define  COMMAND_REG   0x70
#define  DATA_REG      0x71
#define  STATUS_REG    0x71

#define READ_SEC(sec)      outb(SEC,COMMAND_REG);    sec = inb(STATUS_REG)
#define READ_MIN(min)      outb(MIN,COMMAND_REG);    min = inb(STATUS_REG)
#define READ_HOUR(hour)    outb(HOUR,COMMAND_REG);   hour = inb(STATUS_REG)
#define READ_DAYNO(day)    outb(DAYNO,COMMAND_REG);  day = inb(STATUS_REG)
#define READ_DATE(date)    outb(DATE,COMMAND_REG);   date = inb(STATUS_REG)
#define READ_MONTH(month)  outb(MONTH,COMMAND_REG);  month = inb(STATUS_REG)
#define READ_YEAR(year)    outb(YEAR,COMMAND_REG);   year = inb(STATUS_REG)

#define SET_SEC(sec) 	   outb(SEC,COMMAND_REG);    outb(sec,DATA_REG);
#define SET_MIN(min)       outb(MIN,COMMAND_REG);    outb(min,DATA_REG);
#define SET_HOUR(hour)     outb(HOUR,COMMAND_REG);   outb(hour,DATA_REG);
