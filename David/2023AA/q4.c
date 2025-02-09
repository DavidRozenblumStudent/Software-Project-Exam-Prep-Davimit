#include <stdio.h>
#include <stdlib.h>

/* q4 */
#define SWAP(a,b) (a^=b, b^=a, a^=b)

int main(){
    int a = 5, b = 10;
    SWAP(a,b);
    printf("%d %d\n", a, b);
    return 0;
}
