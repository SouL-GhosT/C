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

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

void printArray(int arr[], int n) 
{
    printf("[ ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// int main() 
// {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     if (n <= 0) 
//     {
//         printf("Array size must be positive!\n");
//         return 1;
//     }
//     int arr[n];

//     printf("Enter %d elements:\n", n);
//     for (int i = 0; i < n; i++) 
//     {
//         printf("Element %d: ", i + 1);
//         scanf("%d", &arr[i]);
//     }
//     printf("\nOriginal array: ");
//     printArray(arr, n);


int main() 
{
    int n, choice;

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

    while (1) 
    {
        printf("\n===== SORTING MENU =====");
        printf("\n1. Insertion Sort");
        printf("\n2. Bubble Sort");
        printf("\n3. Selection Sort");
        printf("\n4. Quick Sort");
        printf("\n0. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                insertionSort(arr, n);
                printf("\nArray sorted using Insertion Sort: ");
                printArray(arr, n);
                break;

            case 2:
                bubbleSort(arr, n);
                printf("\nArray sorted using Bubble Sort: ");
                printArray(arr, n);
                break;

            case 3:
                selectionSort(arr, n);
                printf("\nArray sorted using Selection Sort: ");
                printArray(arr, n);
                break;

            case 4:
                quickSort(arr, 0, n - 1);
                printf("\nArray sorted using Quick Sort: ");
                printArray(arr, n);
                break;

            case 0:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}


    