#include <iostream>
#include <cstdlib>

int permutation_next(int *pmt, int size);
void merge_sort(int *arr, int size);
void merge(int *arr, int mid, int size);
void swap(int *a, int *b);

int main()
{
	int i, n, k, rec, *pmt;
	std::cin >> n >> k;
	pmt = (int*)malloc(n * sizeof(int));
	for(i = 1; i <= n; i++)
		pmt[i - 1] = i;

	for(i = 0; i < k - 1; i++)
	{
		rec = permutation_next(pmt, n);
		if(-1 == rec)
		{
			std::cout << "-1";
			return 0;
		}
	}

	for(i = 0; i < n; i++)
		std::cout << pmt[i] << " ";

	free(pmt);
	return 0;
}

int permutation_next(int *pmt, int size)
{
	int i, j, flag = 0;
	for(i = size - 1; i > 0; i--)
	{
		if(pmt[i] > pmt[i-1])
		{
			flag = 1;
			break;
		}
	}
	
	if(0 == flag)
		return -1;
	
	merge_sort(&pmt[i], size - i);

	for(j = i; j < size; j++)
	{
		if(pmt[j] > pmt[i-1])
		{
			swap(&pmt[j], &pmt[i-1]);
			break;
		}
	}
	return 0;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

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
