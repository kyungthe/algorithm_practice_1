#include <iostream>

using namespace std;

int n, M, m[101], c[101];
int min = 0xFFFFFFF, v[101];

void search(int row, int memory, int cost)
{
	if (memory == M || row > n)
	{
		if (cost < min && memory == M)
			min = cost;
		return;
	}

	v[row] = 1;

	for (size_t i = 0; i <= n; i++)
	{
		if (!v[i])
			search(i, memory + m[row], cost + c[row]);
	}

	v[row] = 0;
}

void solve()
{
	search(0, 0, 0);
}

void input()
{
	cin >> n >> M;

	for (size_t i = 0; i < n; i++)
	{
		cin >> m[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> c[i];
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