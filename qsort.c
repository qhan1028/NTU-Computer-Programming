#include <stdlib.h>
#include <stdio.h>

int compare(const void * a, const void * b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	int num[n];
	for (i = 0 ; i < n ; i++) {
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), compare);
	for (i = 0 ; i < n ; i++) {
		printf("%d ", num[i]);
	}
	return 0;
}