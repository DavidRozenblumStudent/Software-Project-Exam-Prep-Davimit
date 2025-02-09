#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} Node;

/* q1 */
int freeTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = freeTree(root->left);
    int right = freeTree(root->right);
    free(root);
    return left + right + 1;
}

/* Tests */

Node* createTree(int h){
    if(h == 0){
        return NULL;
    }
    Node* root = calloc(1, sizeof(Node));
    root->val = h;
    root->left = createTree(h-1);
    root->right = createTree(h-1);
    return root;
}

int main(){
    Node* root = createTree(5);
    printf("%d\n", freeTree(root)); // 31
    return 0;
}

