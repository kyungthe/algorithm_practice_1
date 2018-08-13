/* https://www.acmicpc.net/problem/2577 Quiz */

#include <iostream>

using namespace std;

int main()
{
	int A, B, C;
	int arr[10] = { 0, };

	cin >> A >> B >> C;

	A = A * B * C;

	while (A)
	{
		arr[A % 10]++;
		A /= 10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}