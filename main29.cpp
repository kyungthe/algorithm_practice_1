/* https://www.acmicpc.net/problem/1011 Quiz */

#include <iostream>

using namespace std;

int f(int k)
{
	int n = 2, count = 2, p = 2;

	if (k == 1) return 1;

	for (int i = 0; ; i++)
	{
		if (k - n <= 0)
			return count;
		n += p;
		if (i % 2 == 1)
			p++;
		count++;
	}
}

int main()
{
	int T, x, y;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		cout << f(y - x) << endl;
	}

	return 0;
}