#include <stdio.h>
#include <string.h>

#define COUNTPLUS(s) do{ \
    int count = 0; \
    for(int i = 0; i < strlen(s); i++){ \
        if(s[i] == '+'){ \
            count++; \
        } \
    } \
    printf("The char '+' appears %d times in line: %d\n", count, __LINE__); \
} while(0)

int main(){
    char s[] = "Hello+World+!";
    COUNTPLUS(s);
    char s2[] = "Hello+World+!+";
    COUNTPLUS(s2);
    return 0;
}
