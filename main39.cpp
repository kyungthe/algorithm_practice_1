/* https://www.acmicpc.net/problem/4948 Quiz */

#include <iostream>
#include <vector>

using namespace std;

void SieveOfEratosthenes(vector<int>& v)
{
	for (size_t i = 2; i < v.size(); i++)
	{
		if (v[i] == 1)
			continue;
		for (size_t j = i + i; j < v.size(); j += i)
		{
			v[j] = 1;
		}
	}
}

int main()
{
	int N, count = 0, max = 123456;

	vector<int> v(max * 2 + 1, 0);
	v[1] = 1;
	SieveOfEratosthenes(v);

	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		int end = N + N;
		for (size_t i = N + 1; i <= end; i++)
		{
			if (v[i] == 0)
			{
				count++;
			}
		}
		cout << count << "\n";
		count = 0;
	}

	return 0;
}