#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> extraAdd(long long a, long long b);

int main()
{
	long long a, b;
	std::cin >> a >> b;

	std::vector<int> sum = extraAdd(a, b);
	
	for(std::vector<int>::iterator e = sum.begin(); e != sum.end(); e++)
		std::cout << *e;
	return 0;
}

std::vector<int> extraAdd(long long a, long long b)
{
	std::vector<int> a_str, b_str, c_str;
	long long tmp = 0, mem = 0, i = 0;
	
	if(a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while(0 != a)
	{
		a_str.push_back(a % 10);
		a /= 10;
	}
	while(0 != b)
	{
		b_str.push_back(b % 10);
		b /= 10;
	}

	while(i < a_str.size() && i < b_str.size())
	{
		tmp = a_str[i] + b_str[i] + mem;
		if(tmp > 9)
			mem = 1;
		else
			mem = 0;
		c_str.push_back(tmp % 10);
		i++;
	}
	while(i < a_str.size())
	{
		tmp = a_str[i] + mem;
		if(tmp > 9)
			mem = 1;
		else
			mem = 0;
		c_str.push_back(tmp % 10);
		i++;
	}
	if(1 == mem)
		c_str.push_back(1);
	std::reverse(c_str.begin(), c_str.end());
	return c_str;
}
