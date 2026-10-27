#include <stdio.h>

void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("Array size must be positive!\n");
        return 1;
    }
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal array: ");
    printArray(arr, n);

    insertionSort(arr, n);
    printf("Sorted array:   ");
    printArray(arr, n);
    return 0;
}