#include <stdio.h>

#define FLIPFLOP(x) ((x)^((~0U)<<(sizeof(int)*4)))


int main() {
    int x = 0x7fff5678;
    printf("0x%x\n", FLIPFLOP(x));//
    x = 0;
    x = ~x;
    x = x << (4*sizeof(int));
    printf("0x%x\n", x);//0xffff0000
    return 0;
}