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

int ReadStudent(STUDENT *input, FILE *file)
{
	int count = 0;
	while(fread(input, sizeof(STUDENT), 1, file) > 0) {
		input++;
		count++;
	}
	return count;
}

int main(void) 
{
	FILE *fp1, *fp2;
	char filename1[NAME], filename2[NAME];
	scanf("%s%s", filename1, filename2);
	fp1 = fopen(filename1, "rb");
	fp2 = fopen(filename2, "w");
	assert(fp1 != NULL && fp2 != NULL);

	STUDENT input[10000];
	int count = ReadStudent(input, fp1), i;

	fprintf(fp2, "<table border=\"1\">\n");
	fprintf(fp2, "<tbody>\n");
	for (i = 0 ; i < count ; i++) {
		fprintf(fp2, "<tr>\n");
		fprintf(fp2, "<td>%s</td>\n", input[i].name);
		fprintf(fp2, "<td>%d</td>\n", input[i].id);
		fprintf(fp2, "<td>%s</td>\n", input[i].phone);
		fprintf(fp2, "<td>%f, %f, %f, %f</td>\n", 
			input[i].grade[0], input[i].grade[1], input[i].grade[2], input[i].grade[3]);
		fprintf(fp2, "<td>%d, %d, %d</td>\n",
			input[i].year, input[i].month, input[i].day);
		fprintf(fp2, "</tr>\n");
	}
	fprintf(fp2, "</tbody>\n");
	fprintf(fp2, "</table>\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}