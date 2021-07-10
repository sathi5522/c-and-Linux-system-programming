#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include <stdlib.h>


struct stu{
	int age;
	char name[20];
	}st[10]; 


int main(int argc, char *argv[])
{
	struct stu stp;
	struct stu stc[10];
	int k,l;
	int i =0;
		
	strcpy(st[0].name,"nagesh");
	st[0].age = 20; 

	strcpy(st[1].name,"kamesh");
	st[1].age = 22; 

	strcpy(st[2].name,"rakesh");
	st[2].age = 20; 

	strcpy(st[3].name,"gayathri");
	st[3].age = 22; 

	strcpy(st[4].name,"ravi");
	st[4].age = 20; 

	strcpy(st[5].name,"gunna");
	st[5].age = 22; 
	
	
	strcpy(st[6].name,"lokesh");
	st[6].age = 20; 
	

	strcpy(st[7].name,"gabbar singh");
	st[7].age = 22; 

	
	strcpy(st[8].name,"naga");
	st[8].age = 20; 


	strcpy(st[9].name,"ntr");
	st[9].age = 22; 




	k = open(argv[1],O_RDWR|O_CREAT,00700);
	
	if(k < 0){
		perror("open");
		exit(1);
		}

	write(k,st,sizeof(st));

	lseek(k,0,SEEK_SET);
	read(k,stc,sizeof(stc));
//	lseek(k, (atoi(argv[2])-1)*sizeof(st[0]),   SEEK_SET);
//	l = read(k,&stp,sizeof(stp));

	while(i<10){
		if(!strcmp(stc[i].name,argv[2])){
		printf("%s", stc[i].name);	
		break;
		}
		i++;
	if(i == 10)
	printf("no record");	
		}
		
		

	close(k);
	return 0;

}
