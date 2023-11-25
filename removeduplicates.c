#include <stdio.h>

int removeDuplicates(int arr[], int size)
{
		if (n == 0 || n == 1) //empty array or single element in the array
		return n;

	int temp[n]; //temporary array
  int j = 0;
  
  for (int i = 0; i < n - 1; i++)
		if (arr[i] != arr[i + 1])
			temp[j++] = arr[i];
  temp[j++] = arr[n - 1];

	for (int i = 0; i < j; i++) //copying elements to the original array
		arr[i] = temp[i];

	return j;
}

int main()
{
	int arr[] = { 2,2,4,5,6,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
  removeDuplicates(arr, size);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}
