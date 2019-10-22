#include <stdio.h>

int expmod(long long b, long long e, long long m)
{
	int result = 1;
	b = b % m;
	while (e > 0)
	{
		if(1 == (e % 2))
		{
			result = (result * b) % m;
		}
		e >>= 1;
		b = (b * b) % m;
	}
	return result;
}

int main()
{
	long long b, e, m = 1000000007;
	scanf("%lld %lld", &b, &e);
	printf("%d", expmod(b, e, m));
	return 0;
}
