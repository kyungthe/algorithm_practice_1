#include <iostream>

using namespace std;

int r[11][11];
int v[11];
int n, min = 0x7FFFFFFF;

void search(int a, int b, int s)
{
	v[b] = 1;
	s += r[a][b];

	if (a == n - 1)
	{
		if (s < min)
			min = s;
		return;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (!v[i])
			search(a + 1, i, s);
	}

	v[a] = 0;
}

void solve()
{
	for (size_t i = 0; i < n; i++)
	{
		search(0, i, 0);
	}
}

void input()
{
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> r[i][j];
		}
	}
}

void output()
{
	cout << min << endl;
}

int main()
{
	input();
	solve();
	output();

	return 0;
}