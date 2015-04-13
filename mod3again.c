#include <stdio.h>
int main(void)
{
	int n,i,m;

	scanf("%d",&n);

	int a[n];

	for (i = 0 ; i < n ; i++) 
		scanf("%d",&a[i]);

	scanf("%d",&m);

	int mod[m];

	for (i = 0 ; i < m ; i++) 
		mod[i] = 0;

	for (i = 0 ; i < n ; i++) 
		mod[a[i] % m]++;

	for (i = 0 ; i < m ; i++) 
		printf("%d\n",mod[i]);

	return 0;
}