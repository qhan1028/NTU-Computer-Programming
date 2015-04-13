#include <stdio.h>

#define byte 8

int TestSame(unsigned long long *bookshelf, unsigned long long *book)
{
	int i, temp;
	for (i = 0 ; i < byte ; i++) {
		temp = ((*bookshelf & (255LL << (byte*i))) >> (byte*i));
		if (temp == *book) return i;
	}
	return 0;
}

void Insert(unsigned long long *bookshelf, unsigned long long *book, int *n)
{
	unsigned long long a = 0;
	unsigned long long b = 0;
	int i;
	for (i = *n+1 ; i < byte ; i++) {
		a = a + (*bookshelf & (255LL << (byte*i)));
	}
	for (i = 0 ; i < *n ; i++) {
		b = b + (*bookshelf & (255LL << (byte*i)));
	}
	*bookshelf = (a + (b<<byte) + *book);

	return;
}

int main(void)
{
	unsigned long long bookshelf = 0;
	unsigned long long book = 0;
	int test;

	while (scanf("%lld", &book) != EOF) {
		test = TestSame(&bookshelf, &book);
		if (test != 0)
			Insert(&bookshelf, &book, &test);
		else
			bookshelf = ((bookshelf<<byte) + book);
	}
	int i, temp;
	for (i = byte-1 ; i >= 0 ; i--) {
		temp = ((bookshelf & (255LL << (byte*i))) >> (byte*i));
		printf("%d ", temp);
	}
	return 0;
}