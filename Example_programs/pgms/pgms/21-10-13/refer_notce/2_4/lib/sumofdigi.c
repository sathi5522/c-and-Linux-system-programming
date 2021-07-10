
int sumofdigi(int a)
{
	int sum, rem;

	sum = 0;

	while(a != 0){
		rem = a % 10;
		sum = sum + rem;
		a = a / 10;
	}

	return sum;
}
