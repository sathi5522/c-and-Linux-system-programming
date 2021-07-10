#include <stdio.h>
#include <string.h>

int handle_mp3(char *file_han)
{

	int ret;
	ret = strcmp( (file_han + strlen(file_han))-3,"mp3" );
	if(ret == 0)
		return 1;
	else{
		return 0;
	}

}

void play_mp3(char *play)
{
	int ret;
	ret = handle_mp3(play);
	if(ret)
	printf("audio playing\n");
	else{
	
	printf("cannot hanle\n");
	}

}

void convert_mp3(char *conv)
{

	int ret;
	ret = handle_mp3(conv);
	if(ret)
	printf("audio converting\n");
	else{
	printf("cannot handle\n");
	}
}
