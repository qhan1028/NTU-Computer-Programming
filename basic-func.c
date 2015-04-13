#include <stdio.h>
#include <string.h>
#include "basic.h"

int ReadVars(char varName[][Name], int varValue[])
{
	int count = 0;
	char name[50];

	scanf("%s", name);
	while (strcmp(name, "END") != 0) {
		strcpy(varName[count], name);
		scanf("%s", name);
		scanf("%d", &varValue[count]);
		scanf("%s", name);
		count++;
	}
	return count;
}

int RunASSIGN(int line, char code[5][Name], char varName[][Name], int varValue[], int varNumbers)
{
	int i, operand1, operand2, operand3;

	for (i = 0 ; i < varNumbers ; i++) 
		if (strcmp(code[2], varName[i]) == 0)
			operand2 = varValue[i];

	for (i = 0 ; i < varNumbers ; i++) 
		if (strcmp(code[4], varName[i]) == 0)
			operand3 = varValue[i];

		//printf("%s", code[3]);

	switch (code[3][0]) {
		case '+' :
			operand1 = operand2 + operand3;
			break;
		case '-' :
			operand1 = operand2 - operand3;
			break;
		case '*' :
		 	operand1 = operand2 * operand3;
			break;
		case '/' :
			operand1 = operand2 / operand3;
			break;
		case '%' :
			operand1 = operand2 % operand3;
			break;
		default :
			printf("ASSIGN error.\n");
	}
	for (i = 0 ; i < varNumbers ; i++) 
		if (strcmp(code[0], varName[i]) == 0)
			varValue[i] = operand1;

	return line+1;
}

int RunIF(int line, char code[][Name], char varName[][Name], int varValue[], int varNumbers, int GOTOtarget)
{
	int i, compare, operand1, operand2;

	for (i = 0 ; i < varNumbers ; i++) 
		if (strcmp(code[0], varName[i]) == 0)
			operand1 = varValue[i];

	compare = DetermineCompare(code[1]);

	for (i = 0 ; i < varNumbers ; i++) 
		if (strcmp(code[2], varName[i]) == 0)
			operand2 = varValue[i];

	switch (compare) {
		case 1 :
			if (operand1 == operand2) line = GOTOtarget;
			else line++;
			break;
		case 2 :
			if (operand1 != operand2) line = GOTOtarget;
			else line++;
			break;
		case 3 :
			if (operand1 > operand2) line = GOTOtarget;
			else line++;
			break;
		case 4 :
			if (operand1 < operand2) line = GOTOtarget;
			else line++;
			break;
		case 5 :
			if (operand1 >= operand2) line = GOTOtarget;
			else line++;
			break;
		case 6 :
			if (operand1 <= operand2) line = GOTOtarget;
			else line++;
			break;
		default :
			printf("compare error.");
	}
	return line;
}

int RunPRINT(int line, char *targetName, char varName[][Name], int varValue[], int varNumbers)
{
	int i;

	for (i = 0 ; i < varNumbers ; i++) {
		if (strcmp(targetName, varName[i]) == 0)
			printf("%d\n", varValue[i]);
	}
	return line+1;
}