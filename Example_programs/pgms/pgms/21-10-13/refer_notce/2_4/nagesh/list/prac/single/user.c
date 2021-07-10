#include <stdio.h>
#include "header.h"
#include "error.h"
#include <stdlib.h>
#include <string.h>

struct msg {

	int num;
	char name[10];
};

void disp(q_list  *p)
{
	struct msg *da;
	da = p->data; 
	
	printf("%d %s\n", da->num, da->name );
}


int main()
{

	int ret;
	q_list *start = NULL;
	struct msg *dp= NULL;
	
	dp = malloc(sizeof(struct msg));
	if(dp < 0){
	
		perror("malloc1");
		exit(1);
	}
	dp->num = 1;
	strcpy(dp->name,"nagesh");
	

	ret = insert_first(&start,dp);
	if(ret < 0){
		error_msg("insert_last1:");
		exit(1);
	}

	dp = malloc(sizeof(struct msg));
        if(dp < 0){

                perror("malloc2");
                exit(1);
        }
        dp->num = 2;
        strcpy(dp->name,"ganesh");


	
	ret = insert_first(&start,dp);
	if(ret < 0){
		error_msg("insert_last2:");
		exit(2);
	}
	 dp = malloc(sizeof(struct msg));
        if(dp < 0){

                perror("malloc3");
                exit(1);
        }
        dp->num = 3;
        strcpy(dp->name,"gunna");



	ret = insert_first(&start,dp);
	if(ret < 0){
		error_msg("insert_last3:");
		exit(3);
	}

	dp = malloc(sizeof(struct msg));
        if(dp < 0){

                perror("malloc4");
                exit(1);
        }
        dp->num = 4;
        strcpy(dp->name,"HELLO");
	
	ret = insert_first(&start,dp);
	if(ret < 0){
		error_msg("insert_last4:");
		exit(4);
	}

//	print(start);
   
	display(start, disp);




	ret = delete_last(&start);
	if(ret < 0){
		error_msg("delete_first1:");
		exit(1);
	}
	
	printf("deleted structure is %d\n",ret);




	ret = delete_last(&start);
	if(ret < 0){
		error_msg("delete_first2:");
		exit(2);
	}
	printf("deleted structure is %d\n",ret);



	ret = delete_last(&start);
	if(ret < 0){
		error_msg("delete_first3:");
		exit(3);
	}
	printf("deleted structure is %d\n",ret);



	ret = delete_last(&start);
	if(ret < 0){
		error_msg("delete_first4:");
		exit(4);
	}
	printf("deleted structure is %d\n",ret);

	return 0;
}
