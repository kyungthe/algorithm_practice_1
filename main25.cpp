/* https://www.acmicpc.net/problem/5622 Quiz */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
	string str;
	int result = 0;
	
	cin >> str;

	for (size_t i = 0; i < str.size(); i++)
	{
		int index = str[i] - 'A';
		result += a[index];
	}

	cout << result << endl;

	return 0;
}