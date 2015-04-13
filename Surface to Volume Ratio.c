#include <stdio.h>
main()
{
	int n;

	scanf("%d",&n);

	int a[n],b[n],c[n];
	int i,S,V,mod,A,B;
	float ratio[n],s[n],v[n];

	for (i = 0 ; i < n ; i++) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		s[i] = 2*(a[i]*b[i]+b[i]*c[i]+c[i]*a[i]);
		v[i] = a[i]*b[i]*c[i];
		ratio[i] = s[i] / v[i];
	}

	float min;

	min = ratio[0];

	for (i = 0 ; i < n ; i++) {
		if (ratio[i] < min) min = ratio[i];
	}

	for (i = 0 ; i < n ; i++) {
		if (min == ratio[i]) {
			S = A = s[i];
			V = B = v[i];
			while (S % V > 0) {
				mod = S % V;
				S = V;
				V = mod;
			}
		}
	}
	A = A / V;
	B = B / V;
	
	printf("%d",A);
	printf("%s","/");
	printf("%d",B);

	return 0;
}