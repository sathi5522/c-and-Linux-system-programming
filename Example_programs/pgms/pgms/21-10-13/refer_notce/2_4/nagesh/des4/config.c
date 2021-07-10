#include <stdio.h>
#include "d2.h"
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>
struct image *ih[10];
int no_lib ;

void register_handle(struct image *fs)
{

	ih[no_lib] = fs;
		no_lib++;

}



void loader(char *ext)
{
	FILE *ng ;

	void *k = NULL ;
	char libr[40];
	char *r;
	int re;
	ng = fopen("libname.txt","r");
	
	if(!ng){
		perror("fopen");
		exit(1);
		}
	
	while(1){

		r=fgets(libr,4,ng);
		
		if(!r)
			break;
		re = strcmp(((ext+strlen(ext))-3),libr);
		printf("%s",libr);
//		fseek(ng,1,SEEK_CUR);	

		if(re == 0){	
		r = fgets(libr,sizeof(libr),ng);
		libr[(strlen(libr)-1)] = '\0';
		printf("%s",libr);
		k = dlopen(libr,RTLD_NOW);}
		
	}	
		
		
	


}
