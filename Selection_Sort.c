#include <stdio.h>
 
void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i;
        
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;  
            }
        }
        if (min != i) 
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    
    selectionSort(arr, n);
    printf("Sorted array:   ");
    printArray(arr, n);
    return 0;
}