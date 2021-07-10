#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct student {
	char sname[10];
	int sno;
};
void deletfun(int i, FILE *fp)
{
	int j;
	FILE *fp1;
	struct student readalt;
	struct student r;
	
	fp1 = fopen("tempdatabase.f", "w+");
	if(!fp1){
		perror("open error");
		exit(2);
	}
	for(j = 0; (!feof(fp)) && (j<2); j++){
		
		if(i == j)
			fseek(fp, sizeof(struct student), SEEK_CUR);	
		else{
			fread(&readalt, sizeof(struct student), 1, fp);
			fwrite(&readalt, sizeof(struct student), 1, fp1);
		}
	}
	rewind(fp1);
	while(!feof(fp1)){
		fread(&r, sizeof(struct student), 1, fp1);
		printf("%s\n", r.sname);
	}
	rewind(fp);
	rewind(fp1);
	
	unlink(fp);
	rename( "tempdatabase.f", "databsae.f"); 
}
	
int main()
{
	int x, y, i;
	
	struct student o[3] = {{"mahi", 1}, {"somi", 2}, {"domi", 3}};
	struct student readalt;
	struct student r;
	char comp[9] = "somi";

	FILE *fp;
	fp = fopen("database.f", "w+");
	if(!fp){
		perror("fopen");
		exit(1);
	}
	y = fwrite(o, sizeof(o), 1, fp);
	for(i = 0; i < 3; i++){	
		fseek(fp, sizeof(struct student) * i, SEEK_SET);
		fread(&r, sizeof(struct student), 1, fp);
		
		if(!strcmp(r.sname, comp)){
			rewind(fp);
			printf("i = %d, file found and deleting\n",i); 
			deletfun(i, fp);
			break;
		}
	}	
}
