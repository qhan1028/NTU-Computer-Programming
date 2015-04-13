#include <stdio>
int max(int array[5][5])
{
	int max,i,j,k;

	max = array[0][0];
	for (i = 0 ; i < 5 ; i++) {
		for (j = 0 ; j < 5 ; j++) {
			if (max < array[i][j]) {
				max = array[i][j];
			}
		}
	}
	return max;
}