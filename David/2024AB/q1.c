#include <stdio.h>
#include <stdlib.h>


struct II{
    int id;
    struct II *next;
};

int myCmp(int* a, int* b){
    return (*a) - (*b);
}

int median_degree(struct II* G[], int n){
    int* degrees = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        struct II* current = G[i];
        while(current != NULL){
            degrees[i]++;
            degrees[current->id]++;
            current = current->next;
        }
    }
    // we counted double the degree of each node
    for(int i = 0; i < n; i++){
        degrees[i] /= 2;
    }

    // sort the degrees
    qsort(degrees, n, sizeof(int), myCmp);

    for(int i = 0; i < n; i++){
        printf("%d ", degrees[i]);
    }

    return degrees[n/2];
}


/* Tests */

int main(){
    struct II* G[5];
    G[0] = NULL;
    G[1] = NULL;
    G[2] = NULL;
    G[3] = NULL;
    G[4] = NULL;

    struct II* a = malloc(sizeof(struct II));
    a->id = 1;
    a->next = NULL;
    G[0] = a;

    struct II* b = malloc(sizeof(struct II));
    b->id = 0;
    b->next = NULL;
    G[1] = b;

    struct II* c = malloc(sizeof(struct II));
    c->id = 3;
    c->next = NULL;
    G[2] = c;

    struct II* d = malloc(sizeof(struct II));
    d->id = 2;
    d->next = NULL;
    G[3] = d;

    struct II* e = malloc(sizeof(struct II));
    e->id = 4;
    e->next = NULL;
    G[4] = e;

    printf("%d\n", median_degree(G, 5)); // 2
    return 0;
}


