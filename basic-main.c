#include <stdio.h>
#include <string.h>
#include "basic.h"

int main(void)
{
	// store variables
	char varName[Var][Name];
	int varValue[Var];
	int varNumbers = ReadVars(varName, varValue);

	// store codes
	char PRINTtarget[Line][Name];
	char IFcode[Line][Order][Name];
	char ASSIGNcode[Line][Order][Name];
	int GOTOtarget[Line];

	// line flag
	int code[Line]; 

	// read code
	char name[50];
	int countLine = 1, order;

	while (scanf("%s", name) != EOF) {
		switch (DetermineFunction(name)) {
		case GOTO :
			code[countLine] = GOTO;
			scanf("%d", &GOTOtarget[countLine]);
			break;
		case IF :
			code[countLine] = IF;
			for (order = 0 ; order < 4 ; order++)
				scanf("%s", IFcode[countLine][order]);
			scanf("%d", &GOTOtarget[countLine]);
			break;
		case PRINT :
			code[countLine] = PRINT;
			scanf("%s", PRINTtarget[countLine]);
			break;
		case STOP :
			code[countLine] = STOP;
			break;
		default :
			code[countLine] = ASSIGN;
			strcpy(ASSIGNcode[countLine][0], name);
			for (order = 1 ; order < 5 ; order++)
				scanf("%s", ASSIGNcode[countLine][order]);
		}
		countLine++;
	}
	
	// run code
	int line = 1;
	while (code[line] != STOP) {
		//printf("line:%d\n", line);
		switch (code[line]) {
			case ASSIGN :
				line = RunASSIGN(line, ASSIGNcode[line], varName, varValue, varNumbers);
				break;
			case GOTO :
				line = GOTOtarget[line];
				break;
			case IF :
				line = RunIF(line, IFcode[line],  varName,  varValue,  varNumbers,  GOTOtarget[line]);
				break;
			case PRINT :
				line = RunPRINT(line, PRINTtarget[line], varName, varValue, varNumbers);
				break;
			case STOP :
				break;
			default :
				printf("RunCode Error.");
				return 0;
		}
	}
	return 0;
}