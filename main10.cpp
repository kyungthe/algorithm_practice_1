#include <iostream>

using namespace std;

int arr[500], cnt, n, result[50];

int solve(int num, int index, int max)
{
	int ret = 0;
	if (arr[index] > max)
	{
		ret++;
		max = arr[index];
	}

	int solmax = 0;
	for (size_t i = index + 1; i < n; i++)
	{
		int solret = solve(arr[i], i, max);
		if (solret > solmax)
			solmax = solret;
	}
	ret += solmax;

	return ret;
}

int main()
{
	cin >> cnt;
	for (size_t i = 0; i < cnt; i++)
	{
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		result[i] = solve(arr[0], 0, arr[0]) + 1;
	}

	for (size_t i = 0; i < cnt; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}