/* https://www.acmicpc.net/problem/1003 Quiz */

#include <iostream>

using namespace std;

int main()
{
	int T;
	int zero[50] = { 1, 0 };
	int one[50] = { 0, 1 };

	for (int j = 2; j < 50; j++)
	{
		zero[j] = zero[j - 1] + zero[j - 2];
		one[j] = one[j - 1] + one[j - 2];
	}

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << zero[n] << " " << one[n] << "\n";
	}

	return 0;
}