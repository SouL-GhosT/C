#include <stdio.h>

int binarySearch(int arr[], int n, int target) 
{
    int left = 0;
    int right = n - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;  
        if (arr[mid] == target) 
        {
            return mid;  
        }
        else if (arr[mid] < target) 
        {
            left = mid + 1;  
        }
        else 
        {
            right = mid - 1; 
        }
    } 
    return -1; 
}

void printArray(int arr[], int n) 
{
    printf("[ ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() 
{
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("Array size must be positive!\n");
        return 1;
    }
    int arr[n];

    printf("\nWARNING: Array must be sorted for binary search to work!");
    printf("\nEnter %d elements in SORTED order:\n", n);
    for (int i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nSorted Array: ");
    printArray(arr, n);

    printf("Enter the element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, n, target);
    if (result != -1) 
    {
        printf("Element found at index: %d\n", result);
        printf("Element found at position: %d (1-indexed)\n", result + 1);
        printf("Element value: %d\n", arr[result]);
    } 
    else 
    {
        printf("Element not found in the sorted array!\n");
    }
    return 0;
}