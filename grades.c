#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

char rank[10][10] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F"};
int interval[10] = {90, 85, 80, 77, 73, 70, 67, 63, 60, 0};
float rankgrade[10] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 0};
int hundredgrade[10] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50};

void printRank(int num)
{
	int i;
	for (i = 0 ; i < 10 ; i++) {
		if (num >= interval[i]) {
			printf("%s ", rank[i]);
			return;
		}
	}
}

float getRankGrade(int num)
{
	int i;
	for (i = 0 ; i < 10 ; i++) {
		if (num >= interval[i]) {
			return rankgrade[i];
		}
	}
	return -1;
}

int getHundredGrade(int num)
{
	int i;
	for (i = 0 ; i < 10 ; i++) {
		if (num >= interval[i]) {
			return hundredgrade[i];
		}
	}
	return -1;
}

int main(void)
{
	int grade[MAXN];
	int input, n = 0, i;
	while (scanf("%d", &input) != EOF) {
		grade[n] = input;
		n++;
	}
#ifdef HUNDRED
	int sum = 0;
	for (i = 0 ; i < n ; i++) {
		printf("%d ", grade[i]);
		sum += grade[i];
	}
	printf("%.1f", (float)sum/n);
#endif
#ifdef APLUS
	float rankgradeSum = 0;
	int hundredgradeSum = 0;
	for (i = 0 ; i < n ; i++) {
		printRank(grade[i]);
		rankgradeSum += getRankGrade(grade[i]);
		hundredgradeSum += getHundredGrade(grade[i]);
	}
	printf("%.1f %.1f", (float)rankgradeSum/n, (float)hundredgradeSum/n);
#endif
	return 0;
}