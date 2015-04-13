#include <stdio.h>

int main(void)
{
	long long int a;
	int i;

	while (scanf("%lld", &a) != EOF) {
		for (i = 63 ; i >= 0 ; i--) {
			printf("%lld", (a >> i) & 1);
		}
		printf("\n");
	}
	return 0;
}