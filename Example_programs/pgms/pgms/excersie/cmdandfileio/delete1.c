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
	struct student readalt[3];
	struct student r[3];
//	struct student z = {"hi",10};
	char ch;
	
	fp1 = fopen("tempdatabase.f", "w+");
	if(!fp1){
		perror("open error");
		exit(2);
	}
	for(j = 0; (!feof(fp)) & (j<=2); j++){
		
		if(i == j)
			fseek(fp, sizeof(struct student), SEEK_CUR);	
			//fwrite(&z,sizeof(struct student),1,fp1);
		else{
			fread(&readalt, sizeof(struct student), 1, fp);
			fwrite(&readalt, sizeof(struct student), 1, fp1);
		}

	}
	//fwrite(&ch,1,1,fp1);
	rewind(fp1);
	//for(j = 0; (j<4);j++){
	//while(!feof(fp1)){

	//	fseek(fp1, sizeof(struct student)*j, SEEK_SET); 
		fread(&r, sizeof(struct student), 2, fp1);
	//	fread(&ch,1,1,fp1);
	//	if(fp1 == EOF)
	//		printf("hai\n");
	//	printf("%c\n",ch);
		printf("%s\n", r[0].sname);
		printf("%s\n", r[1].sname);
	//	printf("%s\n", r[2].sname);
		printf("%d\n", r[0].sno);
		printf("%d\n", r[1].sno);
	//	printf("%d\n", r[2].sno);
	//}
	rewind(fp);
	rewind(fp1);
	
	unlink(fp);
	rename( "tempdatabase.f", "databsae.f"); 
}
	

int main()
{
	int i;
	
	struct student o[3] = {{"mahi", 1}, {"somi", 2}, {"domi", 3}};
	struct student r;

	FILE *fp;
	fp = fopen("database.f", "w+");
	if(!fp){
		perror("fopen");
		exit(1);
	}

	fwrite(o, sizeof(o), 1, fp); //at this point offset is at end of 3rd struct last element end, if we do any operation it will be done at 				      //end

	rewind(fp);

		// for comparing student name
	for(i = 0; i < 3; i++){	//	i = 0;
		fseek(fp, sizeof(struct student) * i, SEEK_SET);
		fread(&r, sizeof(struct student), 1, fp);
		
		if(!strcmp(r.sname, "somi")){
			rewind(fp);
			printf("i = %d, file found and deleting\n",i); 
			deletfun(i, fp);
			break;
		}
	}
		
	return 0;
}

