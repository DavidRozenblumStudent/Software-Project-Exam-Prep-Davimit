#include <stdio.h>

#define SWAP(X,Y) (X^=Y, Y^=X, X^=Y)

int main(){
    int x = 5, y = 10;
    SWAP(x, y);
    printf("x = %d, y = %d\n", x, y);
    SWAP(x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}