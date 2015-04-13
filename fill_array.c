#include <stdio.h>

void fill_array(int *ptr[], int n)
{
	int i, j, temp;

	for (i = 0 ; i < n ; i++)
		*ptr[i] = i;

	for (i = 0 ; i < n ; i++) {
		for (j = i ; j < n ; j++) {
			if (ptr[i] > ptr[j]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}

	int *k;

	for (i = 0 ; i < n - 1 ; i++) {
		for (k = ptr[i]+1 ; k < ptr[i+1] ; k++) {
			*k = *ptr[i] + *ptr[i+1];
		}
	}

	return;
}

int main(void)
{
	int *a[6];
	int array[13];

	a[0] = &array[0];
	a[1] = &array[5];
	a[2] = &array[6];
	a[3] = &array[9];
	a[4] = &array[3];
	a[5] = &array[12];

	fill_array(a, 6);

	int i;

	for (i = 0 ; i < 13 ; i++)
		printf("%d ", array[i]);

	return 0;
}