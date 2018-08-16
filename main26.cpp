/* https://www.acmicpc.net/problem/2941 Quiz */

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

bool FindCro(string& str, string& find)
{
	int size = str.size() < find.size() ? str.size() : find.size();
	
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] != find[i])
			return false;
	}

	return true;
}

int main()
{
	string str;
	array<string, 8> finds = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	int count = 0;
	size_t size;
	bool find = false;

	cin >> str;
	size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < finds.max_size(); j++)
		{
			string temp = str.substr(i, size);
			find = FindCro(temp, finds[j]);
			if (find)
			{
				count++;
				i += finds[j].size() - 1;
				break;
			}
		}
		if (!find)
			count++;
		find = false;
	}

	cout << count << endl;

	return 0;
}