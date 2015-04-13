#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"

void print_path(struct node * root, int i, int path[])
{
    if (root != NULL) 
        path[i] = root->data;

    if (root->right == NULL && root->left == NULL) {
        int j;
        for (j = 0 ; j <= i ; j++) {
            printf("%d ", path[j]);
        }
        printf("\n");
        return;
    }
    if (root->left != NULL)
        print_path(root->left, i+1, path);
    if (root->right != NULL)
        print_path(root->right, i+1, path);
}

void print_all_paths(struct node * root) 
{
	if (root == NULL)
        return;
    int path[1000];
    print_path(root, 0, path);
}

int main() {
    int i, values[5] = {1, 7, 8, 9, 15};
    struct node nodes[5];
    for(i = 0; i < 5; i++) {
        nodes[i].data = values[i];
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    nodes[1].left = &nodes[0];
    nodes[1].right = &nodes[2];
    nodes[3].left = &nodes[1];
    nodes[3].right = &nodes[4];
    print_all_paths(&nodes[3]);
    return 0;
}