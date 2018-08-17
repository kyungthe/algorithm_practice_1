/* https://www.acmicpc.net/problem/2775 Quiz */

#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<array<int, 15>, 15> arr = { 0, };

	for (size_t i = 0; i < arr[0].max_size(); i++)
		arr[0][i] = i;

	for (size_t i = 1; i < arr.max_size(); i++)
	{
		for (size_t j = 1; j < arr[i].max_size(); j++)
		{
			for (size_t k = 1; k <= j; k++)
			{
				arr[i][j] += arr[i - 1][k];
			}
		}
	}

	int T, k, n;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}

	return 0;
}