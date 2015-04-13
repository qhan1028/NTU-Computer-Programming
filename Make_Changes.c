#include <stdio.h>
int main(void)
{
	int x;

	int coin50, coin10, coin5, coin1, mod;

	scanf("%d",&x);

	coin50 = x / 50;
	mod = x % 50;

	coin10 = mod / 10;
	mod = mod % 10;

	coin5 = mod / 5;

	coin1 = mod % 5;

	printf("%d\n%d\n%d\n%d", coin50, coin10, coin5, coin1);

	return 0;
}