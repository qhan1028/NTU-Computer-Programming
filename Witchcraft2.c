#include <stdio.h>

int Witchcraft(int Desire, int a, int b, int c, int A, int B, int C)
{
	if (Desire < 0 || a < 0 || b < 0 || c < 0) return 0;
	else if (Desire == 0) return 1;
	else {
		if (Witchcraft(Desire-A, a-1, b, c, A, B, C) == 0) {
			if (Witchcraft(Desire-B, a, b-1, c, A, B, C) == 0) {
				return Witchcraft(Desire-C, a, b, c-1, A, B, C);
			}
		}
	}
}

int main(void)
{
	int N, Desire, a, b, c, A, B, C, i;

	scanf("%d", &N);
	for (i = 0 ; i < N ; i++) {
		scanf("%d%d%d%d%d%d%d", &Desire, &a, &b, &c, &A, &B, &C);
		if (Witchcraft(Desire, a, b, c, A, B, C) >= 1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}