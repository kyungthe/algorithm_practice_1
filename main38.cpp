/* https://www.acmicpc.net/problem/1929 Quiz */

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
	int M, N;
	int sum = 0;
	int first = 0;

	cin >> M >> N;
	vector<int> v(N + 1, 0);
	SieveOfEratosthenes(v);
	v[1] = 1;

	for (size_t i = M; i <= N; i++)
	{
		if (v[i] == 0)
		{
			cout << i << "\n";
		}
	}

	return 0;
}