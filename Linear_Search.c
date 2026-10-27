#include <stdio.h>

int linearSearch(int arr[], int n, int target) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target) 
        {
            return i;
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

    printf("\nEnter %d elements (can be in any order):\n", n);
    for (int i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array: ");
    printArray(arr, n);

    printf("Enter the element to search: ");
    scanf("%d", &target);
    printf("Searching for %d in the array...\n\n", target);
    int result = linearSearch(arr, n, target);
    if (result != -1) 
    {
        printf("Element found at index: %d\n", result);
        printf("Element found at position: %d (1-indexed)\n", result + 1);
    } 
    else 
    {
        printf("Element not found in the array!\n");
    }
    return 0;
}