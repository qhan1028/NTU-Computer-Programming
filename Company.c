#include <stdio.h>
#include <string.h>

typedef struct employee {
	int id;
	char first_name[32];
	char last_name[32];
	int boss_id;
} Employee;

void FindBoss(Employee test, Employee person[], int n, int *Boss, int smallboss)
{
	int i;
	if (test.id == smallboss) {
		*Boss = smallboss;
		return;
	}
	if (test.id == test.boss_id) {
		*Boss = test.boss_id;
		return;
	}
	else {
		for (i = 0 ; i < n ; i++) {
			if (test.boss_id == person[i].id) {
				test.id = person[i].id;
				test.boss_id = person[i].boss_id;
				//printf("%d ", test.id);
				FindBoss(test, person, n, Boss, smallboss);
				return;
			}
		}
	}
}

int Relation(Employee A, Employee B, Employee person[], int n)
{
	int BossA, BossB;
	//printf("\nA :: ");
	FindBoss(A, person, n, &BossA, B.id);
	//printf("\nB :: ");
	FindBoss(B, person, n, &BossB, A.id);
	if (A.boss_id == B.id) {
		//printf(" a -1 ");
		return -1;
	}
	if (A.boss_id == B.boss_id && A.boss_id != A.id && B.boss_id != B.id) {
		//printf(" a 0 ");
		return 0;
	}
		
	if (A.id == B.boss_id) {
		//printf(" a 1 ");
		return 1;
	}
		
	if (BossA == BossB && BossA != A.id && BossB != B.id) {
		//printf(" b 0 ");
		return 0;
	}
		
	if (A.id == BossB) {
		//printf(" b 1 ");
		return 1;
	}
		
	if (BossA == B.id) {
		//printf(" b -1 ");
		return -1;
	}
		

	return -100;
}

int main(void)
{
	int n, i, j;
	scanf("%d", &n);
	Employee person[n];
	for (i = 0 ; i < n ; i++)
		scanf("%d%s%s%d", &person[i].id, person[i].first_name, person[i].last_name, &person[i].boss_id);
	int quest_n;
	Employee A, B;
	scanf("%d", &quest_n);
	for (i = 0 ; i < quest_n ; i++) {
		scanf("%s%s", A.first_name, A.last_name);
		scanf("%s%s", B.first_name, B.last_name);
		for (j = 0 ; j < n ; j++) {
			if (strcmp(A.first_name, person[j].first_name) == 0 && strcmp(A.last_name, person[j].last_name) == 0) {
				A.id = person[j].id;
				A.boss_id = person[j].boss_id;
			}
			if (strcmp(B.first_name, person[j].first_name) == 0 && strcmp(B.last_name, person[j].last_name) == 0) {
				B.id = person[j].id;
				B.boss_id = person[j].boss_id;
			}
		}
		switch (Relation(A, B, person, n)) {
			case 1 :
			printf("supervisor\n");
			break;
			case 0 : 
			printf("colleague\n");
			break;
			case -1 :
			printf("subordinate\n");
			break;
			default :
			printf("unrelated\n");
		}
	}
	return 0;
}