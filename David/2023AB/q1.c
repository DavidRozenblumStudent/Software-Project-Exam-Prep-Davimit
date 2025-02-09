#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    struct node* left;
    struct node* right;
}node;

void add_to_tree(node** root, int val){
    if(*root == NULL){
        *root = calloc(1, sizeof(node*));
        (*root)->val = val;
    }
    else{
        if(val < (*root)->val){
            add_to_tree(&(*root)->left, val);
        }
        else{
            add_to_tree(&(*root)->right, val);
        }
    }
}

node* build_search_tree(int* array, int len){
    node* root = NULL;
    for(int i = 0; i < len; i++){
        add_to_tree(&root, array[i]);
    }

    return root;
}

void free_tree(node* root){
    if(root == NULL){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node* root){
    if(root !=NULL){
        print_tree(root->left);
        printf("%d\n", root->val);
        print_tree(root->right);
    }
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node* root = build_search_tree(array, 10);
    print_tree(root);
    free_tree(root);
    return 0;
}


