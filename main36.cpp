/* https://www.acmicpc.net/problem/1181 Quiz */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	vector<string> v;
	set<string> set;
	string str;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		set.insert(str);
	}
	
	v.assign(set.begin(), set.end());
	sort(v.begin(), v.end(), [](string& str1, string& str2) {
		if (str1.size() == str2.size())
			return str1 < str2;

		return str1.size() < str2.size();
	});

	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << "\n";

	return 0;
}