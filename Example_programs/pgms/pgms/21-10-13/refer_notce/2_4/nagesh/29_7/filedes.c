#include<stdio.h>

int main()
{	
	FILE *fp = NULL;

	
	fp = fopen("filesrc.txt","r");
	int k, nol = 0, noc = 0;
	
	if(!fp)
	{
	
		perror("fopen");
		exit(1);
	}
		

	
	while(k != EOF){
	noc++;
		
	k = fgetc(fp);
	if(k == '\n')
		nol++;
	putchar(k);
	
	}
	
	printf("%d %d", nol, noc);
	fclose(fp);
	return 0;

}
