/* https://www.acmicpc.net/problem/2675 Quiz */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T, R;
	string str;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> R >> str;
		for (size_t j = 0; j < str.size(); j++)
		{
			for (size_t k = 0; k < R; k++)
			{
				cout << str[j];
			}
		}
		cout << "\n";
	}
	return 0;
}