/* https://www.acmicpc.net/problem/9020 Quiz */

#include <iostream>
#include <vector>

#define PRIME		0
#define NO_PRIME	1

using namespace std;

void SieveOfEratosthenes(vector<int>& v)
{
	for (size_t i = 2; i < v.size(); i++)
	{
		if (v[i] == NO_PRIME)
			continue;
		for (size_t j = i + i; j < v.size(); j += i)
		{
			v[j] = NO_PRIME;
		}
	}
}

int main()
{
	int T, N, first, second;
	vector<int> v(10001, PRIME);

	v[1] = NO_PRIME;
	SieveOfEratosthenes(v);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (second = N / 2; second < v.size(); second++)
		{
			if (v[second] == PRIME)
			{
				first = N - second;
				if (v[first] == PRIME)
					break;
			}
		}

		cout << first << " " << second << "\n";
	}

	return 0;
}