#include<stdio.h>

int main(int argc, char *argv[])
{

	FILE  *fd;
	int k;
	char *p = "c programming";

	fd = fopen(argv[1],"a");
	

	if(!fd){
		perror("fopen");
		exit(1);
	}

//	while(k != EOF)
//	   k = fgetc(fd);

	while(*p){
	
		fputc(*p,fd);	
		p++;
		}


	fclose(fd);
	return 0;

}
