#include <stdio.h>
#include <stdlib.h>

// function to reverse array
void reverseArr(int arr[], int beg, int end)
{
    int temp;
    while (beg < end)
    {
        temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++;
        end--;
    }
}

// function to print array
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    printf("Before reversing :\n");
    printArr(arr, arrLength);

    reverseArr(arr, 0, arrLength - 1);

    printf("\nAfter reversing :\n");
    printArr(arr, arrLength);

    return 0;
}