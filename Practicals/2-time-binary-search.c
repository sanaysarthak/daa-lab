#include <stdio.h>
#include <sys/time.h>

int binarySearch(int array[], int startIndex, int endIndex, int x)
{
  if (endIndex >= startIndex)  // used for checking if the position is at the extreme ends of the array or not
  {
    int mid = startIndex + (endIndex - startIndex) / 2;

    // If found at mid, then return it
    if(array[mid] == x)
      return mid;

    // Search the left half
    else if(array[mid] > x) 
      return binarySearch(array,  startIndex, mid - 1,x);

    // Search the right half
    else
        return binarySearch(array, mid + 1, endIndex, x);
  }
  return -1;
}

int main() 
{
    struct timeval start, end;

    int size, ele;
    printf("Enter the size of an array: ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter elements in the array :-\n");
    for(int i=0; i<size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter a number to search it in the array: ");
    scanf("%d", &ele);
    printf("Performing Binary Search algorithm to check whether the number is in the array or not.\n");
    
    gettimeofday(&start, NULL); 
    printf("\nTime before function call = %ld microseconds\n", start.tv_usec);
    
    int res = binarySearch(arr, 0, size-1, ele);
    if (res == -1)
        printf("The number %d is not in the Array.", ele);
    else 
        printf("The number %d is present at index %d.\n", ele, res);
    
    gettimeofday(&end, NULL); 
    printf("Time after function call = %ld microseconds\n", end.tv_usec);
    printf("\nTotal running time = %ld microseconds\n", end.tv_usec - start.tv_usec);
    
    return 0;
}
