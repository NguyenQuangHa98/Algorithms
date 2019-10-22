#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_NUMBER_IN_3MB 750000

void merge(const char *file_name1, int size1, const char *file_name2, int size2);
void sort_to_file(float *arr, int size, const char *file_name);
int partition(float *arr, int start, int end);
void quick_sort(float *arr, int start, int end);
void swap(float *x, float *y);

int main()
{
	int i, n;
	scanf("%d", &n);
	if(n < ELEMENT_NUMBER_IN_3MB)
	{
		float *arr;
		arr = (float*)malloc(n * sizeof(float));
		for(i = 0; i < n; i++)
			scanf("%f", &arr[i]);
		quick_sort(arr, 0, n - 1);
		for(i = 0; i < n; i++)
			printf("%.2f ", arr[i]);
		free(arr);
	}
	else
	{
		float *arr1, *arr2;
		int half_n = n / 2;

		/* sorting first half of given array and write to file */
		arr1 = (float*)malloc(half_n * sizeof(float));
		for(i = 0; i < half_n; i++)
			scanf("%f", &arr1[i]);
		sort_to_file(arr1, half_n, "arr1.txt");
		free(arr1);

		/* sorting the rest of array  and write to file*/
		arr2 = (float*)malloc((n - half_n) * sizeof(float));
		for(i = 0; i < n - half_n; i++)
			scanf("%f", &arr2[i]);
		sort_to_file(arr2, n - half_n, "arr2.txt");
		free(arr2);

		/* merge 2 sorted arrays in 2 files into 1 */
		merge("arr1.txt", half_n, "arr2.txt", n - half_n);
	}
	return 0;
}

void sort_to_file(float *arr, int size, const char *file_name)
{
	FILE *fp;
	quick_sort(arr, 0, size -1);
	fp = fopen(file_name, "wb");
	fwrite(arr, 4, size, fp);
	fclose(fp);
}

void merge(const char *file_name1, int size1, const char *file_name2, int size2)
{
	int i, j, flag1, flag2;
       	float *arr1, *arr2;
	int half1 = size1 / 2, half2 = size2 / 2;
	FILE *fp1, *fp2;
	arr1 = (float*)malloc(half1 * sizeof(float));
	arr2 = (float*)malloc(half2 * sizeof(float));
	fp1 = fopen(file_name1, "rb");
	fread(arr1, 4, half1, fp1);
	fp2 = fopen(file_name2, "rb");
	fread(arr2, 4, half2, fp2);

	flag1 = 0; flag2 = 0, i = 0; j = 0;	
	while(1)
	{
		while(i < half1 && j < half2)
		{
			if(arr1[i] <= arr2[j])
			{
				printf("%.2f ", arr1[i]);
				i++;
			}
			else
			{
				printf("%.2f ", arr2[j]);
				j++;
			}
		}
		if(j < half2)
		{
			if(1 == flag1)
				break;
			half1 = size1 - half1;
			arr1 = (float*)realloc(arr1, half1 * sizeof(float));
			fread(arr1, 4, half1, fp1);
			fclose(fp1);
			flag1 = 1;
			i = 0;
		}
		else
		{
			if(1 == flag2)
				break;
			half2 = size2 - half2;
			arr2 = (float*)realloc(arr2, half2 * sizeof(float));
			fread(arr2, 4, half2, fp2);
			fclose(fp2);
			flag2 = 1;
			j = 0;
		}
	}

	while(i < half1)
	{
		printf("%.2f ", arr1[i]);
		i++;
	}
	if(0 == flag1)
	{
		half1 = size1 - half1;
		arr1 = (float*)realloc(arr1, half1 * sizeof(float));
		fread(arr1, 4, half1, fp1);
		fclose(fp1);
		i = 0;
		while(i < half1)
		{
			printf("%.2f ", arr1[i]);
			i++;
		}

	}
	while(j < half2)
	{
		printf("%.2f ", arr2[j]);
		j++;
	}
	if(0 == flag2)
	{
		half2 = size2 - half2;
		arr2 = (float*)realloc(arr2, half2 * sizeof(float));
		fread(arr2, 4, half2, fp2);
		fclose(fp2);
		j = 0;
		while(j < half2)
		{
			printf("%.2f ", arr2[j]);
			j++;
		}
	}
	free(arr1); free(arr2);
}

void quick_sort(float *arr, int start, int end)
{
	if(start < end)
	{
		int p_index = partition(arr, start, end);
		quick_sort(arr, start, p_index - 1);
		quick_sort(arr, p_index + 1, end);
	}
}

int partition(float *arr, int start, int end)
{
	float pivot = arr[end];
	int i, p_index = start;
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

void swap(float *x, float *y)
{
	float tmp = *x;
	*x = *y;
	*y = tmp;
}
