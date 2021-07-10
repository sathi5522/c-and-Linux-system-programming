#include "header.h"
void unlock(glob_t *p)
{
	
	__sync_fetch_and_sub(p,1);
}
