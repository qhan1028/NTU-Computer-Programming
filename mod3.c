#include <stdio.h>
int main()
{
	int n;

	scanf("%d",&n);

	int a[n],i,j,mod[3] = {0};

	for (i = 0 ; i < n ; i++) {
		scanf("%d",&a[i]);
		for (j = 0 ; j < 3 ; j++) {
			if ((a[i]-j) % 3 == 0) mod[j]++; 
		}
	}

	printf("%d %d %d",mod[0],mod[1],mod[2]);

	return 0;
}