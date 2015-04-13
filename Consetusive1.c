#include <stdio.h>

int main(void)
{
	long long int a;
	int i, count, max;

	while (scanf("%lld", &a) != EOF) {

		count = 0;
		max = 0;

		for (i = 63 ; i >= 0 ; i--) {

			if ( ((a >> i) & 1) == 1) {
				count++;
				if (count >= max)
					max = count;
				else
					continue;
			}
			else
				count = 0;
		}
		printf("%d\n", max);
	}
	return 0;
}