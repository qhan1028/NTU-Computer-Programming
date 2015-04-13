#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is2(char a)
{
	return (a == '0' || a == '2' || a == '4' || a == '6' || a == '8');
}

int is3(char a[], int length)
{
	int sum = 0, i;

	for (i = 0 ; i < length ; i++)
		sum += a[i] - '0';

	return (sum % 3 == 0);
}

int is5(char a)
{
	return (a == '0' || a == '5');
}

int is11(char a[], int length)
{
	int odd = 0, even = 0, i;

	for (i = 0 ; i < length ; i += 2)
		odd += a[i] - '0';

	for (i = 1 ; i < length ; i += 2)
		even += a[i] - '0';

	return ( abs(odd - even) % 11 == 0 );
}

int main(void)
{
	char sample[1000];
	int length, i, j;

	scanf("%s", sample);
	do {
		length = strlen(sample);

		if (is2(sample[length-1]))
			printf("yes ");
		else
			printf("no ");

		if (is3(sample, length))
			printf("yes ");
		else
			printf("no ");

		if (is5(sample[length-1]))
			printf("yes ");
		else
			printf("no ");

		if (is11(sample, length))
			printf("yes\n");
		else
			printf("no\n");

		scanf("%s", sample);

	} while (sample[0] != '-');

	return 0;
}