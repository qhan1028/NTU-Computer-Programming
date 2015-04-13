#include <stdio.h>

int reduce_b(int a, int b)
{
	int i, j, r = 1, c[b+1];

	for (i = 0 ; i < b+1 ; i++)
		c[i] = 0;

	for (i = 1 ; i < b+1 ; i++) {
		r *= a;
		c[i] = r % 1000;
		for (j = 0 ; j < i ; j++) {
			if (r % 1000 == c[j]) {
				return i;
			}
		}
	}
	return b;
}

int main(void)
{
	int a, b, i, r = 1;

	scanf("%d%d",&a,&b);

	b = reduce_b(a, b);

	for (i = 1 ; i <= b ; i++) {
		r = r * a;
	}

	printf("%d", r % 1000);

	return 0;
}