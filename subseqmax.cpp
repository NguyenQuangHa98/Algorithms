#include <iostream>
#include <cstdlib>

int main()
{
	int i, j, n, *arr;
	long long sum, max;
	std::cin >> n;
	arr = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		std::cin >> arr[i];
	
	max = arr[0];
	for(i = 0; i < n; i++)
	{
		sum = 0;
		for(j = i; j < n; j++)
		{
			sum += arr[j];
			if(sum > max)
				max = sum;
		}
	}
	std::cout << max;
	return 0;
}
