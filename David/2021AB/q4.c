#include <stdio.h>

#define SWAP_XOR(a, b) \
    do {               \
        (a) ^= (b);    \
        (b) ^= (a);    \
        (a) ^= (b);    \
    } while (0)


int main(){
    int a = 5, b = 10;
    printf("Before: a = %d, b = %d\n", a, b);
    SWAP_XOR(a, b);
    printf("After: a = %d, b = %d\n", a, b);
    return 0;
}