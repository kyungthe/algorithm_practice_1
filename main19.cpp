/* https://www.acmicpc.net/problem/8958 Quiz */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int test, result = 0, count = 1;
	
	cin >> test;

	for (size_t i = 0; i < test; i++)
	{
		cin >> str;

		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == 'O')
			{
				result += count;
				count++;
			}
			else
				count = 1;
		}
		cout << result << endl;
		result = 0;
		count = 1;
	}	

	return 0;
}