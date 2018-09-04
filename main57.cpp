/* https://www.acmicpc.net/problem/1932 Quiz */

#include <iostream>

using namespace std;

int triangle[500][500];

int main()
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> triangle[i][j];

	for (int i = 1; i < N; i++)
	{
		triangle[i][0] += triangle[i - 1][0];
		for (int j = 1; j < i + 1; j++)
		{
			int left = triangle[i - 1][j - 1];
			int right = triangle[i - 1][j];
			int greater = left > right ? left : right;
			triangle[i][j] += greater;
		}
	}

	int max = triangle[N - 1][0];
	for (int n : triangle[N - 1])
		if (n > max)
			max = n;

	cout << max << endl;
			

	return 0;
}