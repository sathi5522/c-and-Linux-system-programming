#include <stdio.h>
#include "d2.h"

struct image *ih[10];
int no_lib ;

void register_handle(struct image *fs)
{

	ih[no_lib] = fs;
		no_lib++;
	printf("%d\n",no_lib);
}

