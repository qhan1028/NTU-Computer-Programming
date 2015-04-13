#include <stdio.h>
#include <string.h>

void Substraction(int DigitA[], int DigitB[])
{

} 

int main(void)
{
	char sample[100];
	int digit[50], DigitA[50], DigitB[50];
	int i;
	int lengthA, lengthB;

	scanf("%s", sample);
	lengthA = strlen(sample);

	for (i = 0 ; i < lengthA ; i++) 
		digit[i] = sample[i] - '0';

	for (i = 0, j = lengthA-1 ; i < lengthA ; i++ , j--)
		DigitA[j] = digit[i];

	scanf("%s", sample);
	lengthB = strlen(sample);

	for (i = 0 ; i < lengthB ; i++) 
		digit[i] = sample[i] - '0';
 
	for (i = 0, j = lengthB-1 ; i < lengthB ; i++ , j--)
		DigitB[j] = digit[i];

	return 0;
}