
// Linear search using for loop

#include <stdio.h>
#define MAX 50

int main() {
    int a[MAX];
    int size;
    int item;
    int pos = -1; // Initialize pos to -1 to indicate that the element was not found

    printf("Enter the size of array : ");
    scanf("%d", &size);

    printf("Enter the array elements\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element you want to find\n");
    scanf("%d", &item);

    for (int i = 0; i < size; i++) {
        if (a[i] == item) {
            pos = i;
            pos++;
            break;
        }
    }
    if (pos != -1) {
        printf("Element %d found at position %d\n", item, pos);
    } else {
        printf("Element %d not found in the array\n", item);
    }

    return 0;
}
