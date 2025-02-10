#include <stdio.h>


int nbit(unsigned int x){
    int count = 0;
    while(x){
        count += x & 1;
        x >>= 1;
    }
    return count;
}

