#include <stdio.h>

int main(int argc, char *argv[])
{


	FILE *fs, *fd;

	fs = fopen(argv[1],"r");
	
	fd = fopen(argv[2],"w");

	int k;

	if(!fs){

		perror("fopen");
		exit(1);

	}

	if(!fd){
		perror("fopen");
		exit(2);
	}

	while(k != EOF){

	k = fgetc(fs);
		if(k == EOF)
			break;
	fputc(k,fd);

	}


	fclose(fs);
	fclose(fd);



	return 0;
}
