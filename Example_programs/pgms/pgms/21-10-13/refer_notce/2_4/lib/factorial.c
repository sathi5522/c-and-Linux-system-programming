
int factorial(int a)
{
	int fact, i;

	fact = 1;

	for(i = 1; i <= a; i++)
		fact = fact * i;

	return fact;
}
