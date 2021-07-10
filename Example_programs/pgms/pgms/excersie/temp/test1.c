#include <sys/stat.h>
#include<stdio.h>
int main()
{
	int n;
	struct stat obuf;
	chmod("./13.txt", 0440);// or all the permission ids
						// modifying the permissions
	stat("./13.txt", &obuf);
	n =  obuf.st_mode;
        printf("\n%d", n);
	if(S_IRUSR & n)
                printf("\nusr had read per");
        if(S_IWUSR & n)
                printf("\nusr has write");
        if(S_IXUSR & n)
                printf("\nusr has exe");
        if(S_IRGRP & n)
                printf("\ngrp has read");
        if(S_IWGRP & n)
                printf("\ngrp has write");
        if(S_IXGRP & n)
                printf("\n grp has exe");
        if(S_IROTH & n)
                printf("\nother has r");
        if(S_IWOTH &n)
                printf("\nother has w");

        if(S_IXOTH & n)
                printf("\nothr has x");





}
	
