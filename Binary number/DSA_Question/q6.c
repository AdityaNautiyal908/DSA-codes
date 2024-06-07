// Write a program to check whether any of the digits in a number appears more than once:

#include <stdio.h>

int main(){
    int a[5]={1,2,1,1,1};
    int count=0;

    for(int i=0; i<4; i++){
        for(int j=i+1; j<5; j++){
            if(a[i]==a[j]){
            count++;
            break;
            }
        }
    }
    printf("Number of times a number appears more than once: %d",count);
    return 0;
    
}

