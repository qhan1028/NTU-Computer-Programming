#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NAME 100

typedef struct student {
	char name[20];
	int id;
	char phone[10];
	float grade[4];
	int year;
	int month;
	int day;
} STUDENT;