#include <stdio.h>
int main(void)
{
	int x[4], y[4], i, j, result = 0;

	for (i = 0 ; i < 4 ; i++) 
		scanf("%d%d", &x[i], &y[i]);
 
	int vector_x[3], vector_y[3];

	for (i = 1 ; i < 4 ; i++) {
		vector_x[i-1] = x[i] - x[0];
		vector_y[i-1] = y[i] - y[0];
	}

	int cross[3][3];

	for (i = 0 ; i < 3 ; i++) {
		for (j = 0 ; j < 3 ; j++) {
			cross[i][j] = vector_x[i] * vector_y[j] - vector_x[j] * vector_y[i];
		}
	}

	if (cross[1][0] * cross[2][0] < 0) 
		result = ( ( (-y[3] * x[0] + x[3] * y[0]) * (x[3] - x[0]) ) * ( (-y[2] * x[1] + x[2] * y[1]) * (x[2] - x[1]) ) <= 0 && ( (-y[3] * x[1] + x[3] * y[1]) * (x[3] - x[1]) ) * ( (-y[2] * x[4] + x[2] * y[4]) * (x[2] - x[4]) ) <= 0 ) ; 
	
	else if (cross[2][1] * cross[0][1] < 0) 
		result = ( ( (-y[3] * x[2] + x[3] * y[2]) * (x[3] - x[2]) ) * ( (-y[4] * x[1] + x[4] * y[1]) * (x[4] - x[1]) ) <= 0 && ( (-y[2] * x[1] + x[2] * y[1]) * (x[2] - x[1]) ) * ( (-y[3] * x[4] + x[3] * y[4]) * (x[3] - x[4]) ) <= 0 ) ;
	
	else if (cross[1][2] * cross[0][2] < 0) 
		result = ( ( (-y[1] * x[2] + x[1] * y[2]) * (x[1] - x[2]) ) * ( (-y[4] * x[3] + x[4] * y[3]) * (x[4] - x[3]) ) <= 0 && ( (-y[3] * x[1] + x[3] * y[1]) * (x[3] - x[1]) ) * ( (-y[2] * x[4] + x[2] * y[4]) * (x[2] - x[4]) ) <= 0 ) ;

	else
		result = 0;

	printf("%d", result);

	return 0;
}