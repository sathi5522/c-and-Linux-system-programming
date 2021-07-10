#include <stdio.h>

int main()
{

	FILE *fp;
	char *p = "veda solutions";
	fp = fopen("files.txt","w");
	while(*p){
		fputc(*p,fp);
		p++;
	}
	
	fclose(fp);
	return 0;




}
