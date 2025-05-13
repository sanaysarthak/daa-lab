#include <stdio.h>

// Bubble Sort Function
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Binary Search Function
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;  // Key found
        else if (arr[mid] < key)
            low = mid + 1;  // Search right half
        else
            high = mid - 1; // Search left half
    }

    return -1;  // Not found
}

int main() {
    int size, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);
    printf("\nArray after sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    printf("Enter number to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, size, key);
    if (result == -1)
        printf("Number %d not found in array.\n", key);
    else
        printf("Number %d found at index %d.\n", key, result);

    return 0;
}
