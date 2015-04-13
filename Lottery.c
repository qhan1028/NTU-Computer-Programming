#include <stdio.h>
main()
{
	int N;

	scanf("%d",&N);

	int n[N][6];
	int i,j,k;

	for (i = 0 ; i < N ; i++) {
		for (j = 0 ; j < 6 ; j++) {
			scanf("%d",&n[i][j]);
		}
	}

	int r[6],count,prize = 0,single_prize;

	for (i = 0 ; i < 6 ; i++) {
		scanf("%d",&r[i]);
	}

	for (i = 0 ; i < N ; i++) {

		count = 0;
		single_prize = 1;

		for (j = 0 ; j < 6 ; j++) {
			for (k = 0 ; k < 6 ; k++) {
				if (n[i][j] == r[k]) {
					count++;
				}
			}	
		}

		if (count > 0) {
			for (k = 1 ; k <= count ; k++) {
				single_prize = single_prize*10;
			}
		}
		else
			single_prize = 0;

		prize += single_prize;

	}

	printf("%s","Wow! I've won");

	printf(" %d ",prize);

	printf("%s","dollars.");

	return 0;
}  