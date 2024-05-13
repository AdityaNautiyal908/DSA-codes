#include <stdio.h>

void Toh(int n, char beg, char aux, char end){

    if(n==1){
        printf("Move disk 1 from rod %c to rod %c\n",beg,end);
        return;
    }

    Toh(n-1,beg,end,aux);
    printf("Move disk %d from rod %c to rod %c\n",n,beg,end);
    Toh(n-1,aux,beg,end);
}

int main(){
    int n;
    printf("Enter the number of disk : ");
    scanf("%d",&n);
    Toh(n,'A','B','C');

    return 0;
}