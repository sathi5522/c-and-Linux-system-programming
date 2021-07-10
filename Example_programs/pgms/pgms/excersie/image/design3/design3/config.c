#include<stdio.h>
#include<string.h>
#include<dlfcn.h>
#include<stdlib.h>
#include"handlers.h"
struct imagehandler *handlers[10];
int no_libs;
void reg_handler(struct imagehandler *handler) 
{
	handlers[no_libs] = handler;
	no_libs++;
}

void load_handlers(void)
{
	FILE *fp;
	char libname[30];
	void *lib;
	int ret;
	fp = fopen("config.txt","r");
	if(!fp) {
		perror("openerror");
		exit(1);
	}
	while(1) {
		ret = fgets(libname,sizeof(libname),fp);
		if(!ret)
			return;
		libname[strlen(libname)-1]= '\0';
		lib = dlopen(libname,RTLD_NOW);
		if(!lib) {
			printf("%s\n",dlerror());
			exit(2);
		}
	}
	
}
 
