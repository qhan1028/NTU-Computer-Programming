#include <stdio.h>
#include <string.h>

int isVowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int isES(char a, char b)
{
	if (a == 'c' && b == 'h')
		return 1;

	else if (a == 's' && b == 'h')
		return 1;

	else if (b == 's' || b == 'x' || b == 'z')
		return 1;

	else 
		return 0;
}

int main(void)
{
	int n;

	scanf("%d", &n);

	char sample[100];

	int i, length;

	for (i = 0 ; i < n ; i++) {

		scanf("%s", sample);
		length = strlen(sample);

		if (isES(sample[length-2], sample[length-1]))
			strcat(sample, "es");

		else if (isVowel(sample[length-2]) && sample[length-1] == 'y')
			strcat(sample, "s");

		else if (!isVowel(sample[length-2]) && sample[length-1] == 'y')
			strcpy(sample+length-1, "ies");

		else 
			strcat(sample, "s");

		printf("%s\n", sample);
	}
	return 0;
}