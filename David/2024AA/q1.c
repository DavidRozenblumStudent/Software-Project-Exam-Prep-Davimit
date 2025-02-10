#include <stdio.h>
#include <stdlib.h>


typedef struct{
    struct edge* neighbours;
    int index;
}edge;


typedef struct{
    edge* edges;
    int size;
}Graph;

void printG(Graph* g);

Graph* buildG(int edges[][2], int n, int m){
    Graph* ret = calloc(1, sizeof(Graph));
    ret->edges = calloc(n, sizeof(edge));
    ret->size = n;

    for(int i = 0; i < n; i++){
        ret->edges[i].index = i;
    }


    for(int i = 0; i < m; i++){
        int first = edges[i][0];
        int second = edges[i][1];

        edge* temp = calloc(1, sizeof(edge));
        temp->index = second;
        temp->neighbours = ret->edges[first].neighbours;
        ret->edges[first].neighbours = temp;

        temp = calloc(1, sizeof(edge));
        temp->index = first;
        temp->neighbours = ret->edges[second].neighbours;
        ret->edges[second].neighbours = temp;
    }

    return ret;
}


/* Tests */
void freeG(Graph* g){
    for(int i = 0; i < g->size; i++){
        edge* temp = g->edges[i].neighbours;
        while(temp != NULL){
            edge* temp2 = temp;
            temp = temp->neighbours;
            free(temp2);
        }
    }
    free(g->edges);
    free(g);
}

void printG(Graph* g){
    for(int i = 0; i < g->size; i++){
        printf("%d: ", g->edges[i].index);
        edge* temp = g->edges[i].neighbours;
        while(temp != NULL){
            printf("%d ", temp->index);
            temp = temp->neighbours;
        }
        printf("\n");
    }
}

int main(){
    printf("Hello World\n");
    int edges[4][2] = {{0, 1}, {1, 2}, {2, 0}, {5, 6}};
    Graph* g = buildG(edges, 7, 4);
    printG(g);
    freeG(g);
    return 0;
}


