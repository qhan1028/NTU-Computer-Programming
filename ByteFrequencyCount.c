#include <stdio.h>
#include <assert.h>
#define NAME 201

int main(void)
{
	char filename[NAME];
	scanf("%s", filename);
	FILE *fp;
	fp = fopen(filename, "rb");
	assert(fp != NULL);
	int n, i;
	fread(&n, sizeof(int), 1, fp);
	short int num[n];
	int count[70000] = {0};
	fread(num, sizeof(short int), n, fp);
	for (i = 0 ; i < n ; i++) {
		count[(int)num[i]+32768]++;
	}
	int max = 0;
	for (i = 0 ; i < 70000 ; i++) {
		if (count[i] >= count[max]) max = i;
	}
	printf("%d\n%d", max-32768, count[max]);
	fclose(fp);
	return 0;
}