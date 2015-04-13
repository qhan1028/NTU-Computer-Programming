#include <stdio.h>
#include <assert.h>

int main(void)
{
	FILE *fp1, *fp2;
	fp1 = fopen("test", "rb");
	fp2 = fopen("test.enc", "wb");
	assert(fp1&&fp2);
	int a, b;
	scanf("%d", &b);
	while ((a = fgetc(fp1)) != EOF) {
		a = a^b;
		fputc(a, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}