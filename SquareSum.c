#include <stdio.h>

int square(int n)
{
	if (n == 1)
		return 1;
	return ( square(n-1) + n*n);
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d", square(number));
	return 0;
}