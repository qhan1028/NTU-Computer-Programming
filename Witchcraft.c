#include <stdio.h>

void examination(int D, int a, int b, int c, int A, int B, int C)
{
	long long int j, k, l, E;

	for (j = 0 ; j <= a ; j++) {
		for (k = 0 ; k <= b ; k++) {
			for (l = 0 ; l <= c ; l++) {
				E = j * A + k * B + l * C;
				if (E == D) {
					printf("%s\n","yes");
					return;
				}
			}
		}
	}

	printf("%s\n","no");
	return;
}

int main(void)
{
	int N, i;
	long long int a, b, c, A, B, C, D, E;//a b c is amounts. A B C is magic power. D is desire. E is examination.

	scanf("%d",&N);

	for (i = 1 ; i <= N ; i++) {
		scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
		examination(D, a, b, c, A, B, C);
	}

	return 0;
}