/* https://www.acmicpc.net/problem/1193 Quiz */

#include <iostream>

using namespace std;

int main()
{
	int X, n;

	cin >> X;
	
	for (n = 1; ; n++)
	{
		X -= n;
		if (X <= 0)
			break;
	}

	n++;
	X = -X;
	if (n % 2 == 0)
	{
		cout << X + 1 << "/" << n - X - 1 << endl;
	}
	else
	{
		cout << n - X - 1 << "/" << X + 1 << endl;
	}

	return 0;
}