
int palindrome(int a)
{
	int rem, rev, tmp;

	rev = 0;
	tmp = a;

	while(a != 0){

		rem = a % 10;
		rev = (rev * 10) + rem;
		a = a / 10;
	}

	return (tmp == rev) ? 1: 0;

}
