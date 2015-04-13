#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void initMemory(Memory *memory, int length)
{
	int i;
	memory->data = 0;
	for (i = 0 ; i < length-1 ; i++) {
		memory->next = (Memory *)malloc(sizeof(Memory));
		memory = memory->next;
		memory->data = 0;
		//printf("success %d\n", i);
	}
    printf("init suc\n");
	return;
}

void printMemory(Memory *memory)
{
	int start = 0, length = 0, count = 0;
	printf("==========\n");
	while (memory != NULL) {
		if (memory->data == 1) {
			if (length != 0) {
				printf("start %d, length %d\n", start, length);
			}
			length = 0;
			memory = memory->next;
		} else {
			if (length == 0) {
				start = count;
			}
			length++;
			if (memory->next == NULL) {
				printf("start %d, length %d\n", start, length);	
			}
			memory = memory->next;
		}
		count++;
	}
	return;
}

void allocateMemory(Memory *memory, int start, int length)
{
	int i;
	for (i = 0 ; i < start ; i++) {
		memory = memory->next;
	}
	for (i = 0 ; i < length ; i++) {
		memory->data = 1;
		memory = memory->next;
	}
	return;
}

void freeMemory(Memory *memory, int start, int length)
{
	int i;
	for (i = 0 ; i < start ; i++) {
		memory = memory->next;
	}
	for (i = 0 ; i < length ; i++) {
		memory->data = 0;
		memory = memory->next;
	}
	return;
}