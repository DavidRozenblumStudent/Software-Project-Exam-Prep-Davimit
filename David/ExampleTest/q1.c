#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct stack{
    Node* top;
    int size;
}Stack;

Stack* init(const int* arr, size_t size){
    Stack* ret = calloc(1, sizeof(Stack));
    ret->size = size;
    Node* temp;
    int i;
    for(i = size - 1; i >= 0; i--){
        temp = calloc(1, sizeof(Node));
        temp->val = arr[i];
        temp->next = ret->top;
        ret->top = temp;
    }
    return ret;
}

int pop(Stack* stack){
    assert((stack->size > 0) && stack != NULL);
    int value = stack->top->val;
    Node* temp = stack->top;    
    stack->top = stack->top->next;
    stack->size--;
    free(temp);
    return value;
}

int main(){
    Node d = {3, NULL};
    Node* pd = &d;
    printf("%d %d\n", d.val, pd->val);
    pd->val = 5;
    printf("%d %d\n", d.val, pd->val);
    (*pd).val = 7;
    printf("%d %d\n", d.val, pd->val);
    return 0;
}