#include <stdio.h>
int gcd(int a,int b) //最大公因數
{
	int mod;

	while (a % b != 0) {
		mod = a % b;
		a = b;
		b = mod;
	}
	return b;
}

int lcm(int a,int b) //最小公倍數
{
	int lcm_result;

	lcm_result = (a * b) / gcd(a,b);

	return lcm_result;
}

int main(void)
{
	int a,l = 1;

	while (scanf("%d",&a) != EOF) {
		l = lcm(l,a);
	}

	printf("%d",l);

	return 0;
}