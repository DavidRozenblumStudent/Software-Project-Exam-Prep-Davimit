#include <stdio.h>
#include <assert.h>

typedef struct node{
    int val;
    struct node* parent;
    struct node* left;
    struct node* right;
}Node;
/* Q1A */
node deepest_leaf(Node* root){
    assert(root != NULL);
    Node* current = root;
    Node* deepest = root;
    static int curD = 0;
    static int maxD = 0;

    if(current->left != NULL){
        curD++;
        deepest = deepest_leaf(current->left);
        curD--;
    }
    if(current->right != NULL){
        curD++;
        deepest = deepest_leaf(current->right);
        curD--;
    }
    if(curD > maxD){
        maxD = curD;
        deepest = current;
    }

    return deepest;
}

/* Q1B */
int myCmp(void* a, void* b){
    return *(int*)a - *(int*)b;
}

void print_desc(Node* root){
    Node* temp = deepest_leaf(root);
    Node* temp2 = temp;
    int size = 0;
    while(temp){
        size++;
        temp = temp->parent;
    }
    int values = calloc(size, sizeof(int));
    int i = 0;
    while(temp2){
        values[i] = temp2->val;
        i++;
        temp2 = temp2->parent;
    }
    qsort(values, size, sizeof(int), myCmp);

    for(int j = 0; j < size; j++){
        printf("%d  ", values[j]);
    }
}

int main(){
    return 0;
}


