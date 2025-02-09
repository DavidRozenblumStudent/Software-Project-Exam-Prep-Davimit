#include <stdio.h>
#include <stdlib.h>

/* q1 */
typedef struct {
    int val;
    struct node* next;
}node;

typedef struct {
    node** hash;
    int size;
}hashTable;

hashTable* build_table(int* array, int len, int size){
    hashTable* table = calloc(1, sizeof(hashTable));
    table->size = size;
    table->hash = calloc(size, sizeof(node*));
    node* temp;

    for(int i = 0; i < len; i++){
        temp = calloc(1, sizeof(node));
        temp->val = array[i];
        temp->next = table->hash[array[i] % size];
        table->hash[array[i] % size] = temp;
    }

    return table;
}


/* Tests */
void print_table(hashTable* table){
    node* temp;
    for(int i = 0; i < table->size; i++){
        temp = table->hash[i];
        while(temp){
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

void free_table(hashTable* table){
    node* temp;
    for(int i = 0; i < table->size; i++){
        temp = table->hash[i];
        while(temp){
            node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(table->hash);
    free(table);
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 85, 23, 45, 67, 89, 12, 34, 56};
    hashTable* table = build_table(array, 19, 3);
    print_table(table);
    free_table(table);
    return 0;
}




