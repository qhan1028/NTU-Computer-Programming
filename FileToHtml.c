#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct student
{
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int year;
    int month;
    int day;
}
STU;

int main()
{
    FILE *fp_in, *fp_out;
    char bin_name[100], html_name[100];
    scanf("%s", bin_name);
    STU input;
    scanf("%s", html_name);
    fp_in = fopen(bin_name, "rb");
    assert( fp_in != NULL );
    fp_out = fopen(html_name, "w");
    assert( fp_out != NULL );
    fprintf(fp_out, "<table border=\"1\">\n");
    fprintf(fp_out, "<tbody>\n");
    fread(&input, sizeof(STU), 1, fp_in);
    while( !feof(fp_in) )
    {
        fprintf(fp_out, "<tr>\n");
        fprintf(fp_out, "<td>%s</td>\n", input.name);
        fprintf(fp_out, "<td>%d</td>\n", input.id);
        fprintf(fp_out, "<td>%s</td>\n", input.phone);
        fprintf(fp_out, "<td>%f, %f, %f, %f</td>\n", input.grade[0], input.grade[1], input.grade[2], input.grade[3]);
        fprintf(fp_out, "<td>%d, %d, %d</td>\n", input.year, input.month, input.day);
        fprintf(fp_out, "</tr>\n");
        fread(&input, sizeof(STU), 1, fp_in);
    }
    fprintf(fp_out, "</tbody>\n");
    fprintf(fp_out, "</table>\n");
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
