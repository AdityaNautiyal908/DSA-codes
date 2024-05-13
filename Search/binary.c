#include <stdio.h>

int main() {
    int arr[13] = {3, 4, 27, 37, 39, 43, 58, 70, 73, 79, 83, 90, 95};
    int Beg = 0; // Start index
    int End = 12; // End index
    int Mid;
    int loc = -1; // Initialize the location to -1
    int item = 70;

    while (Beg <= End) {
        Mid = (Beg + End) / 2;
        if (item == arr[Mid]) {
            loc = Mid;
            break; // Exit the loop once the item is found
        } else if (item > arr[Mid]) {
            Beg = Mid + 1;
        } else {
            End = Mid - 1;
        }
    }
    if (loc != -1) {
        printf("Item is found at index %d\n", loc);
    } else {
        printf("Item is not found in the array\n");
    }

    return 0;
}
