#include <stdio.h>

int SubsetSum(int sum, int num[], int n)
{
	if (sum == 0)
		return 1;
	if (sum < 0)
		return 0;
	if (n < 0)
		return 0;
	
	return (SubsetSum(sum, num, n-1) + SubsetSum(sum-num[n], num, n-1));
}

int main(void)
{
	int n, i, sum;
	scanf("%d", &n);
	int num[n];
	for (i = 0 ; i < n ; i++)
		scanf("%d", &num[i]);

	while(scanf("%d", &sum) != EOF) {
		printf("%d\n", SubsetSum(sum, num, n-1));
	}
	return 0;
}