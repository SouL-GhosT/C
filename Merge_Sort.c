#include <stdio.h>
 
void merge(int arr[], int left, int mid, int right) 
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int leftArr[leftSize];
    int rightArr[rightSize];
    for (int i = 0; i < leftSize; i++) 
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) 
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0;      
    int j = 0;      
    int k = left;
    while (i < leftSize && j < rightSize) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
 
void mergeSortArray(int arr[], int n) 
{
    mergeSort(arr, 0, n - 1);
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
    
    mergeSortArray(arr, n);
    printf("Sorted array:   ");
    printArray(arr, n);
    return 0;
}