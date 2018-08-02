/* https://algospot.com/judge/problem/read/TRIANGLEPATH ¹®Á¦ */


#include <iostream>

using namespace std;

int n, tri[50][100][100], cache[50][100][100];
int testCase, currentCase, y, x;

int max(int a, int b)
{
	return a > b ? a : b;
}

int search(int y, int x, int sum)
{
	if (y == n)
		return sum;

	int& ret = cache[currentCase][y][x];
	if (ret)
		return ret;

	sum += tri[currentCase][y][x];
	ret += max(search(y + 1, x, sum), search(y + 1, x + 1, sum));
}

void output()
{
	for (size_t i = 0; i < testCase; i++)
	{
		cout << cache[i][y][x] << endl;
	}
}

void input()
{
	cin >> testCase;
	for (size_t k = 0; k < testCase; k++)
	{
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j <= i; j++)
			{
				cin >> tri[k][i][j];
			}
		}
	}
}

int main()
{
	input();
	for (currentCase = 0; currentCase < testCase; currentCase++)
	{
		search(0, 0, 0);
	}
	output();
	return 0;
}