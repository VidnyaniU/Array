/*Given an array of N integers where each value represents the number of chocolates in a packet.
Each packet can have a variable number of chocolates.
There are m students, the task is to distribute chocolate packets such that:

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and the packet
with minimum chocolates given to the students is minimum.
*/

// Approach --> 1. sort the array
//              2. run the loop till i+m-1<n and find the diff between arr[i+m-1] and arr[i]
//              3. find the minimum diff and return

#include <stdio.h>
#include <stdlib.h>
#include <LIMITS.H>

// using merge sort TC=O(nlogn)

// merge fucntion
void mergeM(int arr[], int start, int mid, int end)
{

    // creating 2 subarrays and copying elements into them from original array
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArr[leftSize], rightArr[rightSize];

    for (int i = 0; i < leftSize; i++)

        leftArr[i] = arr[start + i];

    for (int i = 0; i < rightSize; i++)

        rightArr[i] = arr[mid + 1 + i];

    int leftInd = 0, rightInd = 0, arrInd = start;

    // main logic for merge sort
    while (leftInd < leftSize && rightInd < rightSize)
    {
        if (leftArr[leftInd] <= rightArr[rightInd])
        {
            arr[arrInd] = leftArr[leftInd];
            leftInd++;
        }
        else
        {
            arr[arrInd] = rightArr[rightInd];
            rightInd++;
        }
        arrInd++;
    }

    // leftover elements from left subarray
    while (leftInd < leftSize)
    {
        arr[arrInd] = leftArr[leftInd];
        leftInd++;
        arrInd++;
    }

    // leftover elements from right subarray

    while (rightInd < rightSize)
    {
        arr[arrInd] = rightArr[rightInd];
        rightInd++;
        arrInd++;
    }
}

// sort function
void Sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        Sort(arr, start, mid);
        Sort(arr, mid + 1, end);
        mergeM(arr, start, mid, end);
    }
}

int chocoDistribution(int arr[], int m, int n) // m=no of students , n = size of array
{
    // no chocolates or students
    if (m == 0 || n == 0)
        return 0;

    // Number of students cannot be more than number of packets
    if (n < m)
        return -1;

    Sort(arr, 0, n - 1);

    int diff, min = INT_MAX, i = 0; // INT_MAX is highest value of integer
    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min)
        {
            min = diff;
        }
    }

    return min;
}

int main()
{
    int m = 3;
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum difference is %d.", chocoDistribution(arr, m, n));

    return 0;
}