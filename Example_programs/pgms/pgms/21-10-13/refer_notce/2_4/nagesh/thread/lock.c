#include "header.h"

void lock(glob_t *p)
{
	while(*p != 0);
	 __sync_fetch_and_add(p,1);
}
