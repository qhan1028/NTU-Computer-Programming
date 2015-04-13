#include <stdio.h>

int days_of_year(int year) //是否為閏年 回報該年天數
{
    int days = 0, result;

    if (year <= 0) return 0;

    result = ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0 ));

    if (result == 1) days = 366;
    else days = 365;

    return days;
}

int days_of_month(int year, int month) //一個月有幾天
{
    int days;

    switch (month) {

    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    days = 31;
    break;

    case 4: case 6: case 9: case 11:
    days = 30;
    break;

    case 2:
    if (days_of_year(year) == 365) days = 28;
    else days = 29;
    break;

    default:
    days = 0;
  }

  return days;
}

int main(void)
{
	int year, month, n, i, count;

	scanf("%d%d%d", &year, &month, &n);

	if (days_of_month(year, month) == 0 || year > 3000 || year < 1000 || n < 0 || n > 6) {
		printf("%s\n","invalid");
		return 0;
	}

	printf("%s\n%s\n"," Su Mo Tu We Th Fr Sa","=====================");

    for (i = 1 ; i <= n ; i++) 
        printf("   ");

    count = n;

    for (i = 1 ; i <= days_of_month(year, month) ; i++) {

        printf("%3d",i);

        count++;

        if (i == days_of_month(year, month))
            break;

        if (count % 7 == 0) printf("\n");
    }

	printf("\n%s\n","=====================");

	return 0;
}