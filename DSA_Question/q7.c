#include <stdio.h>

int main(){
    int a[]={34, 12, 56, 78, 23, 45, 67, 89, 31, 14,
            52, 76, 98, 41, 63, 25, 87, 19, 37, 58,
            72, 94, 16, 83, 29, 65, 47, 81, 39, 54,
            68, 92, 73, 36, 21, 49, 84, 97, 61, 43};

    printf("%d ",sizeof(a)/sizeof(a[0]));
    return 0;
}