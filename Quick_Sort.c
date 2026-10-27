#include <stdio.h>

// Swap function using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        // Find element greater than pivot
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }
        // Find element smaller than pivot
        while (j >= low + 1 && arr[j] > pivot)
        {
            j--;
        }
        // Swap arr[i] and arr[j]
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    // Put pivot in its correct position
    swap(&arr[low], &arr[j]);
    return j;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Print array
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
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}