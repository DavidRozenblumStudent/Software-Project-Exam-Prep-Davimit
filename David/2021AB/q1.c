#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct hashTable{
    Node* table;
    int size;
} HashTable;

HashTable* createHaseTable(int* array, int len, int size);
void printHashTable(HashTable* hashTable);
void freeHashTable(HashTable* hashTable);

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    HashTable* hashTable = createHaseTable(array, 9, 5);
    printHashTable(hashTable);
    freeHashTable(hashTable);
    return 0;
}


HashTable* createHaseTable(int* array, int len, int size){
    HashTable* hashTable = calloc(1, sizeof(HashTable));
    hashTable->table = calloc(size, sizeof(Node));
    hashTable->size = size;

    printf("Start\n"); // Debugging

    for(int i = 0; i < len; i++){
        Node* newNode = calloc(1, sizeof(Node));
        newNode->data = array[i];
        newNode->next = hashTable->table[array[i] % size].next;
        hashTable->table[array[i] % size].next = newNode;
    }
    printf("End\n"); // Debugging
    return hashTable;
}

void printHashTable(HashTable* hashTable){
    printf("Printing Hash Table\n");
    for(int i = 0; i < hashTable->size; i++){
        Node* current = hashTable->table[i].next;
        while(current != NULL){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void freeHashTable(HashTable* hashTable){
    for(int i = 0; i < hashTable->size; i++){
        Node* current = hashTable->table[i].next;
        while(current != NULL){
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}
