/* https://www.acmicpc.net/problem/1463 Quiz */

#include <iostream>

using namespace std;

int arr[1000001];

void solve(int X, int count)
{
	if (X < 1 || count >= arr[X])
		return;

	if(count < arr[X])
		arr[X] = count;

	if (X % 3 == 0)
		solve(X / 3, count + 1);
	if (X % 2 == 0)
		solve(X / 2, count + 1);
	solve(X - 1, count + 1);
}

int main()
{
	for (int i = 0; i < 1000001; i++)
		arr[i] = 0x7FFFFFFF;

	int X;
	cin >> X;
	solve(X, 0);

	cout << arr[1] << endl;

	return 0;
}