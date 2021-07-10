#include<stdio.h>

int main(int argc,char *argv[])
{

	FILE *fp1,*fp2;
	char c;
	fp1 = fopen(argv[1],"r");
	if(fp1 == NULL) {
		printf("unable to open file");
		exit(1);
	}
	fp2 = fopen(argv[2],"w");
	if(fp2 == NULL) {
		printf("unable to open file");
		exit(1);
	}
	
	while((c = fgetc(fp1))!= EOF){
		fputc(c,fp2);
		printf("%c",c);
	}
//	printf("\n");
	fclose(fp2);
	fclose(fp1);

	return 0;
}	
