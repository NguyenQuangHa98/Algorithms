#include <stdio.h>

int main()
{
	int i, n;
	long long x, sum = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		sum += x;
	}
	printf("%lld", sum % 1000000007);
	return 0;
}
