#include <stdio.h>
#include <stdlib.h>

/* 1d */
#define SWAP(a, b) (a^=b, b^=a, a^=b)


/* 1a */
typedef struct {
    struct Node* next;
    int data;
}Node;

typedef struct {
    Node* top;
    int size;
}Stack;

/* 1b */
Stack* innit(int* array, int size){
    Stack* stack = calloc(1, sizeof(Stack));
    stack->size = size;
    Node* temp = NULL;

    for(int i = size-1; i>=0; i--){
        temp = calloc(1, sizeof(Node));
        temp->next = stack->top;
        temp->data = array[i];
        stack->top = temp;
    }

    return stack;
}

/* 1c */
int pop(Stack* stack){
    Node* temp = stack->top;
    stack->top = stack->top->next;
    int ret = temp->data;
    free(temp);
    return ret;
}

/* Tests */
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    Stack* stack = innit(arr, 5);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));    
    int a,b;
    a=pop(stack);
    b=pop(stack);
    printf("%d %d\n", a, b);
    SWAP(a, b);
    printf("%d %d\n", a, b);
    return 0;
};
