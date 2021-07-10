#include<stdio.h>

int main(int argc,char *argv[])
{
	struct student {
		char name[30];
		int rollno;
		char gender;
		char branch[30];
		int pno;
		char email[30];
	};
	struct student s[10] = {{"abc",123,'m',"def",4561,"xyz@gmail"},{"def",124,'f',"def",4561,"def@gmail"},{"ghi",123,'m',"def",4561,"ghi@gmail"},{"jkl",123,'m',"def",4561,"jkl@gmail"},{"mno",123,'m',"def",4561,"mno@gmail"},{"pqr",123,'m',"def",4561,"pqr@gmail"},{"stu",123,'m',"def",4561,"stu@gmail"},{"vwx",123,'m',"def",4561,"vwx@gmail"},{"yza",123,'m',"def",4561,"yza@gmail"},{"bcd",123,'m',"def",4561,"bcd@gmail"}};
	struct student s1;
	FILE *fp;
	int i,j;
	fp = fopen("file2.txt","w+");
	if(!fp) {
		perror("fopen");
		exit(1);
	}
	fwrite(&s,sizeof(s),10,fp);
//	fread(&s,sizeof(s),10,fp);
	/*for(i = 0;i < 10;i++) {
		printf("\n %s %d %c %s %d %s \n",s[i].name,s[i].rollno,s[i].gender,s[i].branch,s[i].pno,s[i].email);
	}*/
//	rewind(fp);
	for(j =0;j< 10;j++) {
		if(!(strcmp(s[j].name,"bcd"))) {
			fseek(fp,j*sizeof(struct student),SEEK_SET);
			fread(&s1,sizeof(struct student),1,fp);
			printf("name: %s\n",s1.name);
			printf("rollno : %d\n",s1.rollno);
			printf("gender : %c\n",s1.gender);
			printf("branch : %s\n",s1.branch);
			printf("phnum : %d\n",s1.pno);
			printf("email : %s\n",s1.email);
			
			
		}
	}

	return 0;
}

