/* https://www.acmicpc.net/problem/1065 Quiz */

#include <iostream>

using namespace std;

bool solve(int n)
{
	if (n < 100)
		return true;

	int def1 = n / 100;
	n %= 100;
	def1 -= n / 10;
	int def2 = n / 10;
	n %= 10;
	def2 -= n;

	return def1 == def2;
}

int main()
{
	int N, count = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (solve(i))
			count++;
	}

	cout << count << endl;

	return 0;
}