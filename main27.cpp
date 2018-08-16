/* https://www.acmicpc.net/problem/2292 Quiz */

#include <iostream>

using namespace std;

int main()
{
	int N, count = 1;

	cin >> N;

	N -= 1;
	for (int i = 1; ; i++)
	{
		if (N <= 0)
			break;
		count++;
		N -= 6 * i;
	}

	cout << count << endl;

	return 0;
}