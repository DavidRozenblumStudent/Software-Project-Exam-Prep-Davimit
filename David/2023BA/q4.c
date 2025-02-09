#include <stdio.h>
#include <string.h>

#define HALF(x) (strncpy(x, x + strlen(x)/2, (int)(strlen(x)/2)), x[strlen(x)/2] = '\0')

int main(){
    char str[] = "Hello, World!";
    HALF(str);
    printf("%s\n", str);
    return 0;
}