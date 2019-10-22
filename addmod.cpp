#include <iostream>

int main()
{
	long long a, b;
	std::cin >> a >> b;
	long long sum = a + b;
	std::cout << sum % 1000000007;
	return 0;
}
