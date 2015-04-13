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
int value(int type, int width, int height, int length)
{
	int price, volume, max_value, cube, i, min;

	switch (type) { 

		case 79 :
		price = 30;
		break;

		case 47 :
		price = 10;
		break;

		case 29 :
		price = 4;
		break;

		case 82 :
		price = 5;
		break;

		case 26 :
		price = 3;
		break;

		case 22 :
		price = 9;
		break;

		default :
		return -1;
	}

	if (width <= 0 || height <= 0 || length <= 0) {
		return -2;
	}

	volume = width * height * length;

	min = gcd(width, height);
	min = gcd(min, length);

	cube = min * min * min;

	max_value =  price * (volume / cube) * cube * cube;

	return max_value;
}

int main(void)
{
	int type, width, height, length;

	scanf("%d%d%d%d", &type, &width, &height, &length) ;

	printf("%d",value(type, width, height, length));

	return 0;
}