#include <stdio.h>
// Given an integer array nums, return 1 if any value appears at least twice in the array, and return 0 if every element is distinct.
int containsDuplicate(int *nums, int numsSize)
{

    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = containsDuplicate(arr, size);
    ans == 1 ? printf("True!") : printf("False!");

    return 0;
}