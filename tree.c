#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 1000

typedef struct list {
	int data;
	int level;
} List;

typedef struct node {
	int data;
	struct node * right;
	struct node * left;
} Tree;

Tree * consTree(List list[], int n)
{
	if (n == 0) return NULL;

	int found = 0, i, topRoot;
	Tree * root = (Tree *)malloc(sizeof(Tree));
	for (i = 0 ; i < n && !found ; i++) {
		if (list[i].level == 1) {
			root->data = list[i].data;
			topRoot = i;
			found = 1;
		}
	}
	assert(found == 1);

	List small[MAXN];
	int smallNum = 0;
	List large[MAXN];
	int largeNum = 0;

	for (i = 0 ; i < n ; i++) {
		if (list[i].data < list[topRoot].data) {
			small[smallNum].data = list[i].data;
			small[smallNum].level = list[i].level - 1;
			smallNum++;
		}
		else if (list[i].data > list[topRoot].data) {
			large[largeNum].data = list[i].data;
			large[largeNum].level = list[i].level - 1;
			largeNum++;
		}
	}
	root->right = consTree(large, largeNum);
	root->left = consTree(small, smallNum);

	return root;
}

int findDis(Tree * root, int a, int b) 
{
	if (a > root->data && b > root->data) {
		return findDis(root->right, a, b);
	} 
	else if (a < root->data && b < root->data) {
		return findDis(root->left, a, b);
	} 
	else
		return findSubDis(root, a) + findSubDis(root, b);
}

int findSubDis(Tree * root, int n) 
{
	if (n == root->data) return 0;

	if (n > root->data) {
		return findSubDis(root->right, n) + 1;
	}
	else if (n < root->data) {
		return findSubDis(root->left, n) + 1;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	List list[MAXN];
	int i;
	for (i = 0 ; i < n ; i++) {
		scanf("%d%d", &list[i].data, &list[i].level);
	}
	Tree * root = consTree(list, n);
	int m, a, b, distance;
	scanf("%d", &m);
	for (i = 0 ; i < m ; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", findDis(root, a, b));
	}
	free(root);
	return 0;
}