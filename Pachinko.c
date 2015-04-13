#include <stdio.h>

int gcd(int a, int b)
{
	int mod;

	while(a % b != 0) {
		mod = a % b;
		a = b;
		b = mod;
	}

	return b;
}

int main(void)
{
	int N, i, j, k;

	scanf("%d",&N);

	int bucket_n[N+1], bucket_d[N+1];
	int left[N], right[N], denominator[N];
	int Left[N], Right[N], Denominator[N];
	int D, G;

	for (i = 0 ; i < N ; i++)
		Left[i] = Right[i] = Denominator[i] = 1;

	for (i = 0 ; i < N+1 ; i++) 
		bucket_n[i] = bucket_d[i] = 1;


	for (i = 0 ; i < N ; i++) {

		for (j = 0 ; j <= i ; j++) { //讀取

			scanf("%d%d", &left[j], &right[j]);
			
			G = gcd(left[j], right[j]);

			left[j] /= G;
			right[j] /= G;

			denominator[j] = left[j] + right[j];
		}

		for (j = 0 ; j <= i ; j++) { //相乘

			Right[j] = bucket_n[j] * right[j];
			Left[j] = bucket_n[j] * left[j];
			Denominator[j] = bucket_d[j] * denominator[j];
		}

		for (k = 0 ; k < i ; k++) { //相加

			D = Denominator[k] * Denominator[k+1];

			Left[k+1] *= Denominator[k];
			Right[k] *= Denominator[k+1];

			G = gcd(Left[k+1] + Right[k], D);

			bucket_n[k+1] = (Left[k+1] + Right[k])/G;
			bucket_d[k+1] = D/G;
		}

		bucket_n[0] = Left[0];
		bucket_d[0] = Denominator[0];
		G = gcd(bucket_n[0], bucket_d[0]);
		bucket_n[0] /= G;
		bucket_d[0] /= G;

		bucket_n[i+1] = Right[i];
		bucket_d[i+1] = Denominator[i];
		G = gcd(bucket_n[i+1], bucket_d[i+1]);
		bucket_n[i+1] /= G;
		bucket_d[i+1] /= G;
	}

	for (i = 0 ; i < N+1 ; i++) {
		if (bucket_n[i] < 0) bucket_n[i] *= -1;
		if (bucket_d[i] < 0) bucket_d[i] *= -1;
	}

	for (i = 0 ; i < N+1 ; i++) {
		printf("%d/%d\n", bucket_n[i], bucket_d[i]);
	}
	return 0;
}