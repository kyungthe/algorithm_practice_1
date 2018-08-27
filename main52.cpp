/* https://www.acmicpc.net/problem/2747 Quiz */

#include <iostream>

using namespace std;

int arr[100] = { 0, 1 };

int Fibonacci(int n)
{
	if (n == 1 || n == 0)
		return n;

	if (arr[n])
		return arr[n];

	arr[n] = Fibonacci(n - 1) + Fibonacci(n - 2);

	return arr[n];
}

int main()
{
	int n;

	cin >> n;

	cout << Fibonacci(n);

	return 0;
}