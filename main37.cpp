/* https://www.acmicpc.net/problem/2581 Quiz */

#include <iostream>
#include <array>

using namespace std;

void SieveOfEratosthenes(array<int, 10001>& arr)
{
	for (size_t i = 2; i < arr.max_size(); i++)
	{
		if (arr[i] == 1)
			continue;
		for (size_t j = i + i; j < arr.max_size(); j += i)
		{
			arr[j] = 1;
		}
	}
}

int main()
{
	int M, N;
	array<int, 10001> arr = { 1, 1, 0, };
	int sum = 0;
	int first = 0;

	cin >> M >> N;
	SieveOfEratosthenes(arr);

	for (size_t i = M; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			sum += i;
			if (!first)
				first = i;
		}			
	}

	if (first)
		cout << sum << "\n" << first;
	else
		cout << -1;

	return 0;
}