#include <stdio.h>

long long func(long long b, long long e, long long m)
{
	if(0 == e)
		return 1;
	return ((b % m) * func(b, e - 1, m)) % m;
}

int main()
{
	long long b, e, m = 1000000007;
	scanf("%lld %lld", &b, &e);
	printf("%lld", func(b, e, m));
	return 0;
}
