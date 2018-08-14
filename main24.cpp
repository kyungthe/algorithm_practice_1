/* https://www.acmicpc.net/problem/1316 Quiz */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int a[26] = { 0, }, count = 0, N;
	char c;
	bool isGroup = true;

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> str;
		c = str[0];
		a[str[0] - 'a']++;
		for (size_t i = 1; i < str.size(); i++)
		{
			if (a[str[i] - 'a'] && str[i] != str[i - 1])
				isGroup = false;
			a[str[i] - 'a']++;
		}
		if (isGroup)
			count++;
		isGroup = true;
		for (size_t i = 0; i < 26; i++)
			a[i] = 0;
	}

	cout << count << endl;

	return 0;
}