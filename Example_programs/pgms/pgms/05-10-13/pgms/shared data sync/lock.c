extern int flag;
void lock(void)
{
	 while(flag !=0);
        __sync_fetch_and_add (&flag,1);
}
