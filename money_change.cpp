#include <iostream>

const int deno[6] = {1, 5, 10, 50, 100, 500};
const int money_init = 1000;
int main()
{
	int i, n, money_pay, count, deno_cur;
	std::cin >> n;
	
	money_pay = money_init - n;
	deno_cur = sizeof(deno)/sizeof(int) - 1;
	count = 0;
	while(0 != money_pay)
	{
		if(deno[deno_cur] > money_pay)
		{
			deno_cur--;
			continue;
		}
		money_pay -= deno[deno_cur];
		count++;
	}
	std::cout << count;
	return 0;
}
