/* https://www.acmicpc.net/problem/1157 Quiz */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	int a[26] = { 0, };
	int max1, max2;

	cin >> str;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] < 'a')
			a[str[i] - 'A']++;
		else
			a[str[i] - 'a']++;
	}

	max1 = max2 = 0;
	for (size_t i = 1; i < 26; i++)
	{
		if (a[max1] < a[i])
			max1 = i;
	}
	int t = a[max1];
	a[max1] = 0;

	for (size_t i = 1; i < 26; i++)
	{
		if (a[max2] < a[i])
			max2 = i;
	}
	
	if (t == a[max2])
		cout << "?" << endl;
	else
		cout << static_cast<char>('A' + max1) << endl;

	return 0;
}

// 아래는 다른 사람 코드를 보고 고친 것
// VS에서는 실행되지만 백준에서는 실행 안 됨
/*
int main()
{
	string str;
	int a[26] = { 0, };
	int max, maxIndex;

	cin >> str;
	
	transform(str.begin(), str.end(), str.begin(), toupper);
	max = maxIndex = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		int current = str[i] - 'A';
		a[current]++;
		if (max < a[current])
		{
			max = a[current];
			maxIndex = current;
		}
		else if (max == a[current])
			maxIndex = -2;
	}

	cout << static_cast<char>('A' + maxIndex) << endl;

	return 0;
}
*/