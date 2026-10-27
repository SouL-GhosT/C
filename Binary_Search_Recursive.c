#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target) 
{
    if (left > right) 
    {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) 
    {
        return mid;
    }
    else if (target < arr[mid]) 
    {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    else 
    {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
}

int binarySearch(int arr[], int n, int target) 
{
    return binarySearchRecursive(arr, 0, n - 1, target);
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

    printf("\nEnter %d elements in SORTED order:\n", n);
    printf("WARNING: Array must be sorted for binary search!\n\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Sorted Array: ");
    printArray(arr, n);
    
    printf("Enter the element to search: ");
    scanf("%d", &target);
    printf("Searching for %d using Recursive Binary Search...\n\n", target);   
    int result = binarySearch(arr, n, target);
    if (result != -1) 
    {
        printf("Element found at index: %d\n", result);
        printf("Element found at position: %d (1-indexed)\n", result + 1);
        printf("Element value: %d\n", arr[result]);
    } 
    else 
    {
        printf("Element not found in the array!\n");
    }
    return 0;
}