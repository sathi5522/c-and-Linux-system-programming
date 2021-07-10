extern int flag;
void unlock(void)
{
	__sync_fetch_and_sub (&flag,1);
}
