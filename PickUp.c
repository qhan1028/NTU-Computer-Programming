#include <stdio.h>

int PickUp(int num[], int count, int choose, int atleast, int N, int sum)
{
	if (count == N && sum >= 0 && choose >= atleast)
		return 1;
	if (count == N || sum < 0)
		return 0;
	else
		return (PickUp(num, count+1, choose+1, atleast, N, sum-num[count]) + PickUp(num, count+1, choose, atleast, N, sum));
}

int main(void)
{
	int k, N, sum, i, result = 0;
	scanf("%d%d%d", &k, &N, &sum);
	int num[N];
	for (i = 0 ; i < N ; i++)
		scanf("%d", &num[i]);
	result = PickUp(num, 0, 0, k, N, sum);
	printf("%d", result);
	return 0;
}