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


int first_year_days(int year, int month, int day) //第一年還有幾天結束
{
  int days = 0, i;

  for (i = 1 ; i < month ; i++) {
    days = days + days_of_month(year, i);
  }

  days = days + day; //該年過了幾天

  days = days_of_year(year) - days;

  return days;
}

int last_year_days(int year, int month, int day) //最後一年過了幾天
{
  int days = 0, i;

  for (i = 1 ; i < month ; i++) {
    days = days + days_of_month(year, i);
  }

  days = days + day;

  return days;
}

int ndays(int year[2], int month[2], int day[2]) //主函數
{
  int days = 0, year_days = 0, i;

  if (year[0] <= 0 || year[1] <= 0) 
    return -1;

  else if (days_of_month(year[0], month[0]) * days_of_month(year[1], month[1]) == 0) 
    return -1;

  else if ((month[0] == 1 || month[0] == 3 || month[0] == 5 || month[0] == 7 || month[0] == 8 || month[0] == 10 || month[0] == 12) && (day[0] > 31 || day[0] <1))
    return -1;

  else if ((month[1] == 1 || month[1] == 3 || month[1] == 5 || month[1] == 7 || month[1] == 8 || month[1] == 10 || month[1] == 12) && (day[1] > 31 || day[1] <1))
    return -1;

  else if ((month[0] == 4 || month[0] == 6 || month[0] == 9 || month[0] == 11) && (day[0] > 30 || day[0] <1))
    return -1;

  else if ((month[1] == 4 || month[1] == 6 || month[1] == 9 || month[1] == 11) && (day[1] > 30 || day[1] <1))
    return -1;

  else if (days_of_month(year[0], month[0]) == 28 && (day[0] < 1 || day[0] > 28))
    return -1;

  else if (days_of_month(year[1], month[1]) == 28 && (day[1] < 1 || day[1] > 28))
    return -1;

  else if (days_of_month(year[0], month[0]) == 29 && (day[0] < 1 || day[0] > 29))
    return -1;

  else if (days_of_month(year[1], month[1]) == 29 && (day[1] < 1 || day[1] > 29))
    return -1;

  else if (year[0] == year[1] && month[0] < month[1] || year[0] == year[1] && month[0] == month[1] && day[0] <= day[1]) {
    days = -days_of_year(year[0]) + first_year_days(year[0], month[0], day[0]) + last_year_days(year[1], month[1], day[1]);
  }

  else if (year[0] < year[1]) { //兩年之間所有年的天數相加 不包含輸入的兩年
    for (i = year[0]+1 ; i < year[1] ; i++) {
      year_days = year_days + days_of_year(i);
    }
    days = year_days + first_year_days(year[0], month[0], day[0]) + last_year_days(year[1], month[1], day[1]);
  }

  else
    return -1;

  return days;
}

int main(void) //題目
{
  int year[2], month[2], day[2];
  int days;

  scanf("%d", &(year[0]));
  scanf("%d", &(month[0]));
  scanf("%d", &(day[0]));
  scanf("%d", &(year[1]));
  scanf("%d", &(month[1]));
  scanf("%d", &(day[1]));

  days = ndays(year, month, day);
  printf("%d\n", days);
}