#include <stdio.h>
int main()
{
	FILE *fp;

	fp = fopen("data.txt","w+");

	char *p = "welcome to files concept", q[40];

	if(!fp){
		perror("fopen");
		exit(1);
		}

	fputs(p,fp);
	rewind(fp);

	fgets(q,sizeof(q), fp);
	puts(q);

	fclose(fp);
	

	return 0;
}

