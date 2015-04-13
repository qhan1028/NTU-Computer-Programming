#include <stdio.h>

int IsComplete(int quest[], int mod)
{
	int i;
	for (i = 0 ; i < mod ; i++) {
		if (quest[i] != 0) return 0;
	}
	return 1;
}

void PickNum(int num[], int n, int lastNum, int quest[], int mod, int result[], int count, int all)
{
	int i;
	if (IsComplete(quest, mod)) {
		for (i = 0 ; i < all ; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	else {
		if (n >= lastNum)
			return;

		if (quest[num[n] % mod] > 0) {
			quest[num[n] % mod]--;
			result[count] = num[n];
			PickNum(num, n+1, lastNum, quest, mod, result, count+1, all);
			quest[num[n] % mod]++;
		}
		PickNum(num, n+1, lastNum, quest, mod, result, count, all);
	}
}

int main(void)
{
	int n, i, j, temp, mod;
	scanf("%d", &n);
	int num[n];
	for (i = 0 ; i < n ; i++) {
		scanf("%d", &num[i]);
	}
	for (i = 0 ; i < n ; i++) {
		for (j = i+1 ; j < n ; j++) {
			if (num[i] > num[j]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	scanf("%d", &mod);
	int quest[mod], all = 0;
	for (i = 0 ; i < mod ; i++) {
		scanf("%d", &quest[i]);
		all += quest[i];
	}
	int result[all];
	for (i = 0 ; i < all ; i++) {
		result[i] = 0;
	}
	PickNum(num, 0, n, quest, mod, result, 0, all);
	return 0;
}