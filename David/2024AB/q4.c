#include <stdio.h>


void permute(char* a, int l, int r){
    if(l==r){
        printf("%s\n", a);
    }
    for(int i = l; i <= r; i++){
        char temp = a[l];
        a[l] = a[i];
        a[i] = temp;
        permute(a, l+1, r);
        temp = a[l];//important to swap back
        a[l] = a[i];
        a[i] = temp;
    }
}


int main(){
    char a[] = "abc";
    permute(a, 0, 2);
    return 0;
}



