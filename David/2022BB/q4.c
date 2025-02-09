#include <stdio.h>
#include <stdlib.h>


/* Q4 */
void shift_left_3(int arr[]){
    for(int i = 0; i < 3; i++){
        arr[0] = arr[0] << 1;
        if(arr[1] < 0){
            arr[0] += 1;
        }
        arr[1] = arr[1] << 1;
    }
}


/* Tests */
int main(){
    int arr[] = {1, -1};
    shift_left_3(arr);
    printf("%d %d\n", arr[0], arr[1]); // 15 -8

    return 0;
}
