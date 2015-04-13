#define Line 1010
#define Name 30
#define Var 110
#define Order 10
#define ASSIGN 0
#define GOTO 1
#define IF 2
#define PRINT 3
#define STOP 4

int ReadVars(char varName[][Name], int varValue[]);
int RunASSIGN(int line, char code[5][Name], char varName[][Name], int varValue[], int varNumbers);
int RunIF(int line, char code[][Name], char varName[][Name], int varValue[], int varNumbers, int GOTOtarget);
int RunPRINT(int line, char *targetName, char varName[][Name], int varValue[], int varNumbers);
int DetermineFunction(char *name);
int DetermineCompare(char *code);