#include <stdio.h>
int main(void)
{
	int size, i, j, k;

	scanf("%d",&size);

	int x[3], y[3], count[3], d[3];

	for (i = 0 ; i < 3 ; i++) 
		count[i] = 0;

	for (i = 0 ; i < 3 ; i++) 
		scanf("%d%d", &x[i], &y[i]);

	for (i = 0 ; i <= size ; i++) {
		for (j = 0 ; j <= size ; j++) {
			for (k = 0 ; k < 3 ; k++) {
				d[k] = (i - x[k]) * (i - x[k]) + (j - y[k]) * (j - y[k]);
			}
			if (d[0] < d[1] && d[0] < d[2]) count[0]++;
			else if (d[0] <= d[1] && d[0] <= d[2] && ((x[0] < x[1] && d[0] == d[1]) || (x[0] < x[2] && d[0] == d[2]))) count[0]++;
			else if (d[0] <= d[1] && d[0] <= d[2] && x[0] <= x[1] && x[0] <= x[2] && ((y[0] < y[1] && x[0] == x[1] && d[0] == d[1]) || (y[0] < y[2] && x[0] == x[2] && d[0] == d[2]))) count[0]++;

			if (d[1] < d[0] && d[1] < d[2]) count[1]++;
			else if (d[1] <= d[0] && d[1] <= d[2] && ((x[1] < x[0] && d[1] == d[0]) || (x[1] < x[2] && d[1] == d[2]))) count[1]++;
			else if (d[1] <= d[0] && d[1] <= d[2] && x[1] <= x[0] && x[1] <= x[2] && ((y[1] < y[0] && x[1] == x[0] && d[1] == d[0]) || (y[1] < y[2] && x[1] == x[2] && d[1] == d[2]))) count[1]++;
			
			if (d[2] < d[1] && d[2] < d[0]) count[2]++;
			else if (d[2] <= d[1] && d[2] <= d[0] && ((x[2] < x[1] && d[2] == d[1]) || (x[2] < x[0] && d[2] == d[0]))) count[2]++;
			else if (d[2] <= d[1] && d[2] <= d[0] && x[2] <= x[1] && x[2] <= x[0] && ((y[2] < y[1] && x[2] == x[1] && d[2] == d[1]) || (y[2] < y[0] && x[2] == x[0] && d[2] == d[0]))) count[2]++;
		}
	}

	for (i = 0 ; i < 3 ; i++) 
		printf("%d\n", count[i]);

	return 0;
}