#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}Node;

void concat_trees(Node* root1, Node* root2){
    assert(root1 && root2);
    while(root1->right){
        root1 = root1->right;
    }
    root1->right = root2;
}

void print_depth(Node* root){
    static int curr_depth = 0;
    static int max_depth = 0;
    
    if(curr_depth == 0 && max_depth == 0){ // to only print once
        if(root){
            curr_depth++;
            if(curr_depth > max_depth){
                max_depth = curr_depth;
            }
            print_depth(root->left);
            print_depth(root->right);
            curr_depth--;    
        }    
        printf("Max depth: %d\n", max_depth);         
    }
    else if(root){
        curr_depth++;
        if(curr_depth > max_depth){
            max_depth = curr_depth;
        }
        print_depth(root->left);
        print_depth(root->right);
        curr_depth--;
    }
}
    

int main(){
    

    return 0;
}
