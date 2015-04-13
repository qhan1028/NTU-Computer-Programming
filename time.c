#include <stdio.h>
#include "time.h"

void initTime(Time *time)
{
	time->hour = 0;
	time->minute = 0;
	time->second = 0;
	return;
}

void setTime(Time *time, int hour, int minute, int second)
{
	time->hour = hour;
	time->minute = minute;
	time->second = second;
	return;
}

void addTime(Time *time, int hour, int minute, int second)
{
	int excess = 0;
	time->second += second;
	if (time->second >= 60) {
		time->second -= 60;
		excess = 1;
	}
	excess = 0;
	time->minute = time->minute + minute + excess;
	if (time->minute >= 60) {
		time->minute -= 60;
		excess = 1;
	}
	time->hour = time->hour + hour + excess;
	if (time->hour >= 24)
		time->hour -= 24;
	return;
}

void printTime(Time *time) 
{
#ifdef H24
	if (time->hour < 10) 
		printf("0%d", time->hour);
	else 
		printf("%d", time->hour);
#endif
#ifndef H24
	if (time->hour <= 12) {
		if (time->hour < 10) 
			printf("0%dam", time->hour);
		else if (time->hour >= 10 && time->hour < 12)
			printf("%dam", time->hour);
		else if (time->hour == 12)
			printf("%dpm", time->hour);
	}
	else if (time->hour > 12) {
		time->hour -= 12;
		if (time->hour < 10) 
			printf("0%dpm", time->hour);
		else if (time->hour >= 10 && time->hour < 12)
			printf("%dpm", time->hour);
	}
#endif
	printf(":");
	if (time->minute < 10)
		printf("0%d", time->minute);
	else 
		printf("%d", time->minute);
	printf(":");
	if (time->second < 10)
		printf("0%d", time->second);
	else 
		printf("%d", time->second);
	return;
}