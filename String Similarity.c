#include <stdio.h>
#include <string.h>

void Test1(char a[], int length, int count[])
{
	int i, j;

	for (i = 0 ; i < length ; i++) {
		for (j = 0 ; j < 26 ; j++) {
			if (a[i] >= 97 && a[i] <= 122 && a[i]-97 == j) {
				count[j]++;
				break;
			}
			else if (a[i] >= 65 && a[i] <= 90 && a[i]-65 == j) {
				count[j]++;
				break;
			}
		}
	}
	return;
}

int Test2(int a[], int b[])
{
	int i;
	for (i = 0 ; i < 26 ; i++) {
		if (a[i] == b[i])
			continue;
		else
			return 0;
	}
	return 1;
}

int main(void)
{
	int n, i, j;

	scanf("%d", &n);

	char sampleA[100001], sampleB[100001];
	int lengthA, lengthB;
	int A[26] = {0}; 
	int B[26] = {0};

	for (i = 0 ; i < n ; i++) {

		scanf("%s%s", sampleA, sampleB);
		lengthA = strlen(sampleA);
		lengthB = strlen(sampleB);
		Test1(sampleA, lengthA, A);
		Test1(sampleB, lengthB, B);

		if (Test2(A, B))
			printf("yes\n");

		else
			printf("no\n");

		for (j = 0 ; j < 26 ; j++) {
			A[j] = 0;
			B[j] = 0;
		}
	}
	return 0;
}