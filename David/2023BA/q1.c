#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rowIdx;
    int colIdx;
    int val;
    struct node* next;
} node;

node* build_list(int* matrix, int n, int m){
    node* head = NULL;
    node** temp = &head;

    for(int i = 0; i < n*m; i++){
        if(matrix[i] != 0){
            node* newNode = calloc(1, sizeof(node));
            newNode->val = matrix[i];
            newNode->rowIdx = i/m;// + 1; cosmetic change (1-indexed)
            newNode->colIdx = i%m;// + 1;
            (*temp) = newNode;
            temp = &(newNode->next);
        }
    }

    return head;
}

int trace(node* head){
    if(!head) {return 0;}
    int sum = trace(head->next);
    if(head->rowIdx == head->colIdx){
        sum += head->val;
    }
    return sum;
}

void free_list(node* head){
    node* temp = head;
    while(temp){
        node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main(){
    int matrix[4][4] = {
        {1, 0, 0, 8},
        {0, 0, 2, 0},
        {0, 4, 0, 3},
        {0, 5, 0, 7}
    };

    node* head = build_list((int*)matrix, 4, 4);
    node* temp = head;
    while(temp){
        printf("row: %d, col: %d, val: %d\n", temp->rowIdx, temp->colIdx, temp->val);
        temp = temp->next;
    }
    printf("Trace: %d\n", trace(head));
    free_list(head);
    return 0;
}
