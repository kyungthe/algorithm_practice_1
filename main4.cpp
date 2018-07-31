#include <iostream>
#include <queue>
#include <list>

using namespace std;

int g[201][201], v[201] , n, m;

void solve()
{
	list<int> list;

	list.push_front(0);
	while (!list.empty())
	{
		int current = list.front(); list.pop_front();
		v[current] = 1;
		for (auto i = list.begin(); i != list.end(); i++)
		{
			if (current == *i)
			{
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			if (!v[i] && g[current][i])
				list.push_front(i);
		}
	}

	cout << "OK" << endl;

	return;
}

void output()
{

}

void input()
{
	int s, e;

	cin >> n >> m;
	for (size_t i = 1; i <= m; i++)
	{
		cin >> s >> e;
		g[s][e] = g[e][s] = 1;
	}
}

int main()
{
	input();
	solve();
	output();

	return 0;
}