#include<stdio.h>

int main(int argc,char *argv[])
{

        FILE *fp1;
        char c;
	int count = 0,ln = 0;
        fp1 = fopen(argv[1],"r");
        if(fp1 == NULL) {
                printf("unable to open file");
                exit(1);
        }
	while((c=fgetc(fp1))!=EOF) {
		count++;

		if(c == '\n') {
			ln++;
		}
	}
	printf("the no of characters is:%d\n",count);

	printf("the no of lines is : %d",ln);
}
	

