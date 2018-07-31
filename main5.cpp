#include <iostream>

using namespace std;

int n, A[101], sum, max;

void solve()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i; j < n; j++)
		{
			sum += A[j];
			if (sum > max)
				max = sum;
		}
		sum = 0;
	}
}

void input()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> A[i];
	}
}

void output()
{
	cout << max << endl;
}

int main()
{
	input();
	solve();
	output();

	return 0;
}