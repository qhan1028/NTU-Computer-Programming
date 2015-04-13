#include <stdio.h>
#include <string.h>
#include "basic.h"

int DetermineFunction(char *name)
{
	int i;
	char *string[4] = {"GOTO", "IF", "PRINT", "STOP"};

	for (i = 0 ; i < 4 ; i++) 
		if (strcmp(name, string[i]) == 0)
			return i+1;
	
	return 0;
}

int DetermineCompare(char *code)
{
	char *string[6] = {"==", "!=", ">", "<", ">=", "<="};
	int i;

	for (i = 0 ; i < 6 ; i++)
		if (strcmp(code, string[i]) == 0)
			return i+1;

	return 0;
}