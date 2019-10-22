#include <stdio.h>
#include <stdlib.h>

void comb_sort(float *a, int n);
void swap(float *a, float *b);

int main()
{
	int i, n;
	float *a;

	scanf("%d", &n);
	a = (float*)malloc(n * sizeof(float));
	for(i = 0; i < n; i++)
		scanf("%f", &a[i]);

	comb_sort(a, n);
	for(i = 0; i < n; i++)
		printf("%.2f ", a[i]);
	free(a);
	return 0;
}

void comb_sort(float *a, int n)
{
	int i = 0, gap = n, sorted = 0;
	float shrink = 1.3;

	while(1 != gap || 0 == sorted)
	{
		
		/* calculate next gap */
		gap = int((float)gap / shrink);
		if(gap < 1)
			gap = 1;
		sorted = 1;

		for(i = 0; i < n - gap; i++)
		{
			if(a[i] > a[i + gap])
			{
				swap(&a[i], &a[i + gap]);
				sorted = 0;
			}
		}
	}
}

void swap(float *a, float *b)
{
	float tmp = *a;
	*a = *b;
	*b = tmp;
}
