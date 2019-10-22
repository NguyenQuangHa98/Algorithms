#include <iostream>
#include <stack>
#include <string>

int is_pair(char a, char b)
{
	if(('(' == a && ')' == b) || ('[' == a && ']' == b) || ('{' == a && '}' == b))
		return 1;
	return 0;
}

int paren_check(std::string pattern)
{
	std::stack<char> st;
	for(std::string::iterator c = pattern.begin(); c != pattern.end(); c++)
	{
		if('(' == *c || '[' == *c || '{' == *c)
			st.push(*c);
		else if(st.empty())
			return 0;
		else
		{
			if(0 == is_pair(st.top(), *c))
				return 0;
			st.pop();
		}
	}
	/* check stack is empty or not */
	if(!st.empty())
		return 0;

	return 1;
}

int main()
{
	int i, n;
	std::string  pattern;

	std::cin >> n;
	std::cin.ignore();
	
	for(i = 0; i < n; i++)
	{
		std::getline(std::cin, pattern);
		if(pattern.empty())
		{	std::cout << "1\n";
			return 0;
		}
		std::cout << paren_check(pattern) << '\n';
	}
	return 0;
}
