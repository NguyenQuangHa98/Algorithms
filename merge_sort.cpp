#include <cstdlib>
#include "merge_sort.h"

void merge_sort(int *arr, int size)
{
	if (size < 2)
		return;
	int mid = size / 2;
	merge_sort(arr, mid);
	merge_sort(arr + mid, size - mid);
	merge(arr, mid, size);
}

void merge(int *arr, int mid, int size)
{
	int leftSize = mid, rightSize = size - mid;
	int *leftArr = (int*)malloc(leftSize * sizeof(int));
	int *rightArr = (int*)malloc(rightSize * sizeof(int));
	int i, j, k;
	for (i = 0; i < leftSize; i++)
		leftArr[i] = arr[i];
	for (j = 0; j < rightSize; j++)
	{
		rightArr[j] = arr[i];
		i++;
	}
	i = 0; j = 0; k = 0;
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++; k++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++; k++;
		}
	}
	while (i < leftSize)
	{
		arr[k] = leftArr[i];
		i++; k++;
	}
	while (j < rightSize)
	{
		arr[k] = rightArr[j];
		j++; k++;
	}
	free(leftArr); free(rightArr);
}
