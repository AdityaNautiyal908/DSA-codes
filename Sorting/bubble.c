#define MAX 100

int main(){
    int size;
    int arr[MAX];
    printf("Enter the size of array : ");
    scanf("%d",&size);
    printf("Enter the element of array : ");
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    printf("Array element before sorting\n");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int j=0; j<size; j++){
    for(int i=0; i<size-1; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp; // Corrected swapping logic
        }
    }
}
    printf("Array element after sorting\n");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}