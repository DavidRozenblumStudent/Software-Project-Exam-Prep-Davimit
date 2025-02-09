#include <stdio.h>

#define BYTES_SWAP(x) ((x & 0x000000FF) << 24 | (x & 0x00FFFF00) | (x & 0xFF000000) >> 24)

int main(){
    int x = 0x12345678;
    printf("%x\n", BYTES_SWAP(x));
    return 0;
}

