#include <stdio.h>


	struct stu{

		char name[20];
		int  age;
		char g;
		int  rn;
	};





alter(FILE *j,int l)
{
	int k;	
	struct stu r;
	char m[] = "hello"; 
	printf("enter which record u want to print");
	scanf("%d",&k);
	fseek(j,(k-1)*l,SEEK_SET);
//	fwrite(&m,sizeof(m),1,j);
//	fseek(j,(k-1)*l,SEEK_SET);
	fread(&r,l,1,j);
	printf("name : %s\n age : %d\n g :  %c\nrn : %d",r.name, r.age, r.g, r.rn);
}



del(FILE *j,FILE *d, int l)
{

	int i = 1,n;
	struct stu r;
	char na[20];

	printf("search name\n");
	scanf("%s",na);

	while(i <= 10){
		
		fread(&r, l,1,j);
		n = strcmp(na,r.name);

			if(n != 0){
				
				fwrite(&r,l,i,d);
			}
			
				fseek(j,l*i,SEEK_SET);
		        i++;
		
	
	}
		
}

search(FILE *j, int l)
{

	int i = 1,n;
	struct stu r;
	char na[20];

	printf("search name\n");
	scanf("%s",na);

	while(i <= 10){
		
		fread(&r, l,1,j);
		n = strcmp(na,r.name);

			if(n == 0){
					printf("name :%s\n age : %d\n, g : %c\n rn : %d",r.name,r.age,r.g,r.rn);
					break;
			}
			else{
				fseek(j,l*i,SEEK_SET);
			}
			
		        i++;
			if(i == 10)
			printf("no record");
	
	}
		
}




int main()
{
	FILE *fp,*fd;
	fp = fopen("record.txt","w+");
	fd = fopen("reco.txt","w");


	struct stu rec1  = {"gunna",  20,  'm',   201};
	struct stu rec2  = {"nagesh", 21,  'm',  202};
	struct stu rec3  = {"kamesh", 22,  'm',  203};
	struct stu rec4  = {"ravi",   23,  'm',  204};
	struct stu rec5  = {"raj",    24,  'm',  205};
	struct stu rec6  = {"nani",   25,  'm',  206};
	struct stu rec7  = {"raja",   26,  'm',  207};
	struct stu rec8  = {"luck",   27,  'm',  208};
	struct stu rec9  = {"lovely", 28,  'f',  209};
	struct stu rec10 = {"madam",  29,  'f',  210};
	struct stu *q,r;
	
	q = &rec1;


	if(!fp){
		perror("fopen");
		exit(1);
		}

	if(!fd){
		perror("fopen");
		exit(2);
		}



	fwrite(q, sizeof(rec1),10,fp);
	rewind(fp);
	
//	del(fp,fd,sizeof(rec1));
	
	
	alter(fp,sizeof(rec1));
//	search(fp,sizeof(rec1));


	fclose(fp);

	return 0;

}
