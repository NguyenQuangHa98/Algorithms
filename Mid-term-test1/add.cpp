#include <iostream>
#include <vector>

int main()
{
	std::vector<int> sum;
	long long a, b, tmp, mem = 0;
	std::cin >> a >> b;
	
	if(0 == a && 0 == b)
	{
		std::cout << 0;
		return 0;
	}
	while(0 != a && 0 != b)
	{
		tmp = a % 10 + b % 10 + mem;
		mem = tmp / 10;
		sum.insert(sum.begin(), tmp % 10);
		a /= 10;
		b /= 10;
	}
	while(0 != a)
	{
		tmp = a % 10 + mem;
		mem = tmp / 10;
		sum.insert(sum.begin(), tmp % 10);
		a /= 10;
	}
	while(0 != b)
	{
		tmp = b % 10 + mem;
		mem = tmp / 10;
		sum.insert(sum.begin(), tmp % 10);
		b /= 10;
	}
	if(0 != mem)
		sum.insert(sum.begin(), mem);

	for(std::vector<int>::iterator it = sum.begin(); it != sum.end(); it++)
		std::cout << *it;
	return 0;
}

