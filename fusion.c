#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[100000];
	char input[128];
	char temp1[128], temp2[128];
	int i,j;
	int lengthIn, lengthStr;
	int flag = 0;

	while (scanf("%s", input) != EOF) {
		lengthIn = strlen(input);
		lengthStr = strlen(string);
		printf("%d %d\n", lengthIn, lengthStr);
		flag = 0;
		for (i = lengthIn ; i >= 0 ; i--) {
			strncpy(temp1, input, i);
			for (j = lengthStr-i-1 ; j < lengthStr ; j++) {
				strncpy(temp2, &string[])
				if (strcmp() == 0 && (flag == 0)) {
					strcpy(&string[j], input);
					flag = 1;
				}
			}
		}
		if (flag == 0) strcat(string, input);
	}
	printf("%s", string);
	return 0;
}