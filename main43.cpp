/* https://www.acmicpc.net/problem/9012 Quiz */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	string input;
	int result;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> input;
		result = 0;
		for (auto it = input.begin(); it != input.end(); it++)
		{
			result += *it == '(' ? 1 : -1;
			if (result < 0)
				break;
		}
		if (result == 0)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}