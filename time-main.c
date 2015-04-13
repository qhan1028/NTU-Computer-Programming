#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main(void)
{
	Time *time = (Time *)malloc(sizeof(Time));
	initTime(time);
	setTime(time, 15, 56, 17);
	addTime(time, 1, 8, 56);
	printTime(time);
	return 0;
}