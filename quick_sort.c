#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int start, int end);
void quick_sort(int *arr, int start, int end);
void swap(int *x, int *y);

int main()
{
	int i, n, *arr;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quick_sort(arr, 0, n - 1);
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}

void quick_sort(int *arr, int start, int end)
{
	if(start < end)
	{
		int p_index = partition(arr, start, end);
		quick_sort(arr, start, p_index - 1);
		quick_sort(arr, p_index + 1, end);
	}
}

int partition(int *arr, int start, int end)
{
	int pivot = arr[end], p_index = start;
	int i;
	for(i = start; i < end; i++)
	{
		if(arr[i] <= pivot)
		{
			swap(&arr[i], &arr[p_index]);
			p_index++;
		}
	}
	swap(&arr[p_index], &arr[end]);
	return p_index;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
